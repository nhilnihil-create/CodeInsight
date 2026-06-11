#include <bits/stdc++.h>
using namespace std;
int main(void){
    map<string,int> memo;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        memo[s]++;
    }
    int maxv=0;
    for(const auto& x : memo){
        int v=x.second;
        maxv=max(v,maxv);
    }
    for(auto it=memo.begin();it!=memo.end();it++){
        if(it->second==maxv) cout << it->first << endl;
    }
}