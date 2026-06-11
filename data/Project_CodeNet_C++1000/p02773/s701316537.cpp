#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    int ma = 0;
    map<string, int> cnt;
    for(int i = 0; i < n; i++){
        cin >> s;
        cnt[s]++;
        ma = max(ma, cnt[s]);
    }

    for(auto &u : cnt){
        if(u.second == ma){
            cout << u.first << "\n";
        }
    }
    return 0;
}