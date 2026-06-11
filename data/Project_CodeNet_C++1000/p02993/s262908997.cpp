#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
ll mod = 1000000007;

int main(){
    string s;cin>>s;
    bool f=true;
    rep(i,0,3){
        if (s[i]==s[i+1]) f=false;
    }
    if (f){
        cout<<"Good"<<endl;
    }else{
        cout<<"Bad"<<endl;
    }
}