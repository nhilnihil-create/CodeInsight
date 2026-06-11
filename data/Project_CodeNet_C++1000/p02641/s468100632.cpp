#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod=1000000007;
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int x,n,t,ans=INT_MAX,j=0;
 cin>>x>>n;
 vector<int> d(105,0);
 for(int i=0; i<n;i++){
    cin>>t;
    d[t]=1;
 }
 for(int i=0; i<=101; i++){
    if(d[i]==0){
        if(ans>abs(x-i)){ans=abs(x-i); j=i;}
    }
 }
 cout<<j;
    return 0;
}