#include<iostream>
#include<bits/stdc++.h>
#include<climits>
#include<math.h>

#define forn(x,n,s) for(int i = x; i < n; i += s )
#define forr(x,n,s) for(int i = x; i>=n; i -= s)
#define PI 3.14159265358979323846264338327950L

using namespace std;

void go(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
  #endif
} 
long long int mod = 1e9+7;

int main(){
    go(); 

    // code here
    int a,b,c,k;cin>>a>>b>>c>>k;
    int sum = 0;
    sum = min(a,k);
    k = max(0,k - a); 
    if(k!=0) k = max(0,k - b);
    if(k!=0) sum -= min(c,k);
    cout<<sum;
}



