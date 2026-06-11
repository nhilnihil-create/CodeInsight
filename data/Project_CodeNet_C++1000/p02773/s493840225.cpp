#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
    int n; cin >> n;
    
    map<string, int> mp;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        mp[s] += 1;
    }
    int max_v = 0;
    for(const auto& x : mp){
        int v = x.second;
        if(v > max_v) max_v = v;
    }           
    for(auto it=mp.begin(); it!=mp.end(); it++){
        if(it->second == max_v){
            cout << it->first << endl;
        }
    }
}