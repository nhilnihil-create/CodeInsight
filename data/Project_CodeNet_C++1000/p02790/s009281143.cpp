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
    //input
    int a,b;
    cin>>a>>b;
    string s1,s2;
    string s;
    s1="";
    rep(i,b){
        if(i==0){
            s=to_string(a);
        }
        s1+=s;
    }
    s2="";
    rep(i,a){
        if(i==0){
            s=to_string(b);
        }
        s2+=s;
    }
    if(a<=b){
        cout<<s1<<endl;
    }else{
        cout<<s2<<endl;
    }
}