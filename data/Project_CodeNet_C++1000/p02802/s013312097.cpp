#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
int main(){
    long long N, M;
    cin >> N >> M;
    vector<long long> p(M);
    vector<string> S(M);
    set<int> s;
    vector<int> cnt(100010, 0);
    int cntac = 0, cntwa = 0;
    for(int i = 0; i < M; i++) {
        cin >> p[i] >> S[i];
        if(!s.count(p[i]) && S[i] == "AC") {
            cntac++;
            s.insert(p[i]);
        }
        if(!s.count(p[i]) && S[i] == "WA") {
            cnt[p[i]]++;
        }
    }
    for(int i = 0; i < 100010; i++){
        if(s.count(i)) cntwa += cnt[i];
    }
    cout << cntac << ' ' << cntwa << endl; 
}