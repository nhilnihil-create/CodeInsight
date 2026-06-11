#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    map<string,int> m;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        m[s] += 1;
    }
    int maxn=0;
    for(auto& x : m){
        int v = x.second;
        maxn = max(maxn, v);
    }
    for(auto x : m){
        if(x.second == maxn){
            cout << x.first << endl;
        }
    }
}