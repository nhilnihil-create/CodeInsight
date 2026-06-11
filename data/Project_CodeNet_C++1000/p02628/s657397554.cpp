#include<iostream>
#include<bits/stdc++.h>
#include<climits>

#define forn(x,n,s) for(int i = x; i < n; i += s )
#define forr(x,n,s) for(int i = x; i>=n; i -= s)

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
    int n,k;cin>>n>>k;
    int arr[n];
    forn(0,n,1) cin>>arr[i];
    sort(arr,arr+n);
    int sol = 0;
    forn(0,k,1) sol += arr[i];
    cout<<sol;
    
}




