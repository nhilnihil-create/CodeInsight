#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
int main() {
    string s;cin>>s;
    vector<int> num(s.size()+1);
    rep(i,s.size()+1){
        num[i]=0;
    }
    rep(i,s.size()){
        if(s.at(i)=='<') num[i+1]=num[i]+1;
    }
    for(ll i=s.size()-1;i>=0;i--){
        if(s.at(i)=='>') num[i]=max(num[i+1]+1,num[i]);
    }
    ll sum=0;
    rep(i,s.size()+1){
        sum+=num[i];
    }
    cout<<sum<<endl;
}