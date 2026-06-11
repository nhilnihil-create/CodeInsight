#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    map<string,int> mp;
    int b = 0;
    rep(i,n){
        string s;
        cin >> s;
        mp[s]++;
        int now = mp[s];
        b = max(b,now);
    }
    for(auto a = mp.begin(); a!=mp.end(); a++){
        if(a->second==b){
            cout << a->first << endl;
        }
    }
    return 0;
}