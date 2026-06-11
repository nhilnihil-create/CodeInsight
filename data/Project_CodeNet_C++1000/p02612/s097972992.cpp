#include<bits/stdc++.h> 
#define ll long long 
#define pb push_back 
#define vec vector<int> 
#define fo(i,n) for (ll i = 0; i < n; i++)
#define so(v) sort(v.begin(), v.end())
#define fi first
#define se second 
using namespace std;  
int main()
{
 int n;
 cin>>n;
 int a;
 a=n%1000;
 if(a==0)
 {
    cout<<0;
    
 }
 else if(a<1000)
 {
     a=1000-a;
     cout<<a;
 }
 
}