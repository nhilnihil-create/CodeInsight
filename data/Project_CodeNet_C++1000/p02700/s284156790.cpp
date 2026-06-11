#include<iostream>
#include<bits/stdc++.h>
#include<climits>
#include<math.h>

#define forn(x,n,s) for(int i = x; i < n; i += s )
#define forr(x,n,s) for(int i = x; i>=n; i -= s)
#define PI 3.14159265358979323846264338327950L
#define MOD 1e9+7

using namespace std;

void go(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
  #endif
} 

int main(){
    go(); 

    // code here
    int a,b,c,d;cin>>a>>b>>c>>d;
    double x = (double)a/d;
    x = ceil(x);
    double y = (double)c/b;
    y = ceil(y);
    cout<<(x>=y?"Yes":"No");
} 

