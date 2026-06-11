#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,k,s;
    cin>>n>>k>>s;
    ll res = s+1;
    if(s == 1e9) res = 1;
    vector<int> a(n,s+1);
    for(int i=0; i<k; i++) cout<<s<<" ";
    for(int i=k; i<n; i++) cout<<res<<" ";
}