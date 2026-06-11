

#include <bits/stdc++.h>
using namespace std;

///idea: https://atcoder.jp/contests/abc174/submissions/15671761
/***
I changed the binary search to the standard BINARY search that I use ALWAYS 
and 100% OK
*/ 

int maxN=2e5+5;
int n,k;
vector<int>a(maxN);

bool isValid(int mid){
    int kk = 0; 
    if(mid==0)
        return false;
    for(int i=0;i<n;i++){
        if(a[i]<=mid)
            continue;
        int t=a[i]/mid;
        kk += t; ////t ta cut korsi ei log ke
    }
    return (kk<=k);///kk<=k hole EI MID or largest log value possibel
}
void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int lo=0,hi=1e9+5;
    while(lo<=hi){
        int mid=(lo+hi)/2; 
        if(isValid(mid)){
            hi=mid-1;
        }
        else{
            lo = mid+1; 
        }
            
    }
    cout<<lo<<"\n"; 
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve(); 
    return 0;
}
