#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<long long> P(N);
    for(int i = 0; i < N; i++) cin >> P[i];
    vector<int> ind(N);
    for(int i = 0; i < N; i++) ind[i] = i;
    sort(ind.begin(), ind.end(), [&](int x, int y){
        return P[x] > P[y];
    });
    set<int> s;
    long long ans = 0;
    s.insert(ind[0]);
    long long a, b, c, d;
    for(int i = 1; i < N; i++){
        s.insert(ind[i]);
        auto ite = s.find(ind[i]);
        auto ite2 = ite;
        a = (++ite == s.end()) ? N : *ite;
        if(ite == s.end()) ite--;
        b = (++ite == s.end()) ? N : *ite;
        c = (ite2 == s.begin()) ? -1 : *(--ite2);
        d = (ite2 == s.begin()) ? -1 : *(--ite2);
        long long temp = (ind[i] - c) * (b - a) + (a - ind[i]) * (c - d);
        ans += temp * P[ind[i]];
    }
    cout << ans << endl;
}