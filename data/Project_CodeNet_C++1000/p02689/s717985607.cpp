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
    int n,m;cin>>n>>m;
    long long height[n],mh[n];
    forn(0,n,1){
       cin>>height[i];
       mh[i] = 0;
    }
    forn(0,m,1){
        int a,b;cin>>a>>b;
        mh[a-1] = max(mh[a-1],height[b-1]);
        mh[b-1] = max(mh[b-1],height[a-1]);
    }
    int cnt = 0;
    forn(0,n,1){
        cnt += (height[i]>mh[i]);
    }
    cout<<cnt;
}



