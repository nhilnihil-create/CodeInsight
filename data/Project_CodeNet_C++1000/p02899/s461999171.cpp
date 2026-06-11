#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> p;
    rep(i,n){
        int a;
        cin>>a;
        p.push_back({a,i+1});
    }
    sort(p.begin(),p.end());
    for(auto x:p){
        cout<<x.second<<endl;
    }
}