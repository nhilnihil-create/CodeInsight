#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    string s;cin>>s;
    map<char,int>m;
    rep(i,s.size()){
        if(m.count(s.at(i))){
            m[s.at(i)]++;
        }else{
            m[s.at(i)]++;
        }
    }
    for (auto p :m) {
        auto key = p.first;
        auto value = p.second;
    // key, valueを使う
        if(value!=2){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}