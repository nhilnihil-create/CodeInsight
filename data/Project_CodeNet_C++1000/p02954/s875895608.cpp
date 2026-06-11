#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
using namespace std;
typedef pair<char, char> P;
int main(){
    string S;
    cin >> S;
    vector<int> cnt(S.size(), 0);
    set<int> sr, sl;
    for(int i = 0; i < S.size() - 1; i++){
        if(S[i] == 'R' && S[i + 1] == 'L'){
            sr.insert(i);
            sl.insert(i + 1);
        }
    }
    int cntr = 0, cntl = 0;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == 'R') cntr++;
        else cntr = 0;
        if(sr.count(i)){
            cnt[i] += (cntr + 1) / 2;
            cnt[i + 1] += cntr / 2;
        }
    }
    for(int i = S.size() - 1; i >= 0; i--){
        if(S[i] == 'L') cntl++;
        else cntl = 0;
        if(sl.count(i)){
            cnt[i] += (cntl + 1) / 2;
            cnt[i - 1] += cntl / 2;
        }
    }
    for(int i = 0; i < S.size(); i++){
        if(i != S.size() -1) cout << cnt[i] << ' ';
        else cout << cnt[i] << endl;
    }
}