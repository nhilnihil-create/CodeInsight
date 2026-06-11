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
    int N;cin>>N;
    int max=0;
    string tmp;
    map<string,int>s;
    vector<string>s2(N);
    rep(i,N){
        cin>>tmp;
        if(s.count(tmp)){
            s[tmp]++;
        }else{
            s[tmp]=1;
        }
        if(s[tmp]>max){
            max=s[tmp];
        }
    }
    int j=0;
    for(auto p:s){
        auto key=p.first;
        auto value=p.second;
        if(value==max){
            cout<<key<<endl;
        }
    }

}