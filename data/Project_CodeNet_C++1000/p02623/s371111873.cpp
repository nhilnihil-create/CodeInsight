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
    int n,m,k;cin>>n>>m>>k;
    long long arr1[n+1] = {0ll},arr2[m+1] = {0ll};
    forn(1,n+1,1) cin>>arr1[i];
    forn(1,m+1,1) cin>>arr2[i];
    forn(2,n+1,1) arr1[i] += arr1[i-1]; 
    forn(2,m+1,1) arr2[i] += arr2[i-1];
    int ans = 0;
    for(int i = 0;i < n+1; i++){
        int start = 0,end = m;
        while(start<=end){
            int mid = start + (end - start)/2;
            if(arr2[mid]<=(k-arr1[i])){
                ans = max(ans,mid+i);
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        } 
    }
    cout<<ans;
   
    
}




