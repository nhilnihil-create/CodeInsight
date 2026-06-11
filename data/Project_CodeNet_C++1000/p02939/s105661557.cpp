#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
   string s;cin >>s;
   string pre="";
   int ans=0;
   int n=s.size();
   int i=0;
    while(i<n){
        string c="";
        c+=s[i];
        if(pre==c){
            i++;
            if(i==n)break;
            c+=s[i];
        }
        pre=c;
        ans++;
        i++;
    }
    cout <<ans <<endl;
}
