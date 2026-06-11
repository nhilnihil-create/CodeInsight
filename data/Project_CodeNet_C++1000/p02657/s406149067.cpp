#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long int
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(),v.rend() //reverse
#define vl vector<long long>v(n);
#define mii unordered_map<ll,ll>
#define pb push_back
double pi = 2*acos(0.0);
ll power(ll a,ll b){ ll res=1;while(b){if(b&1)res=res*a;b=b/2; a=(a*a); }return res;}



 int main()
 {
       ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
       ll tst;
       tst=1;
       //cin>>tst;
    
       while(tst--)
       {
        ull a,b;
        cin>>a>>b;
        cout<<a*b<<endl;
        
       }
 
 }