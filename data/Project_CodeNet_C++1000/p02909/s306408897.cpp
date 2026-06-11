#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    string s;cin >>s;
    if(s[0]=='S'){
        puts("Cloudy");
    }
    else if(s[0]=='C'){
        puts("Rainy");
    }
    else puts("Sunny");
    return 0;
}

