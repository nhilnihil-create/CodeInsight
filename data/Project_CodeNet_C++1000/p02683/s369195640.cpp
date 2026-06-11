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
    int n,m,k;cin>>n>>m>>k;
    int cost[n];
    vector<vector<int>> arr(n,vector<int>(m));
    forn(0,n,1){
        cin>>cost[i];
        for(int j = 0; j < m; j++){
            cin>>arr[i][j];
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i < (1<<n); i++){
        vector<int> temp(m,0);
        int temp_c = 0; 
        for(int j = 0; j < n;j++){
            if(i&(1<<j)){
                for(int k = 0;k < m;k++){
                    temp[k] += arr[j][k]; 
                }
                temp_c += cost[j];
            }
        }
        int flag = 0;
        for(int x:temp){
            if(x<k){
                flag = 1;
                break;
            }
        }
        if(flag == 0) ans = min(ans,temp_c);
    }
    if(ans==INT_MAX) cout<<-1;
    else cout<<ans;
}