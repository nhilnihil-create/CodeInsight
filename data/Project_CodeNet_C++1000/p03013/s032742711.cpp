#include <bits/stdc++.h>
using namespace std;

const int mod = (int)1e+9 + 7;

bool binary_search(int start, int end, int value, vector<int>&sorted){
    
    while(start <= end){
        int mid = start + (end - start)/2;
        if(sorted[mid] == value){
            return true;
        }else if(sorted[mid] > value){
            start = mid + 1;
        }else{
            end = mid - 1;
        }
    }
    
    return false;
    
}


int main(){
    
    int n, m;
    cin >> n >> m;
    vector<int>broken(m);
     vector<int>dp(n+1, INT_MAX);
    for(int i = 0; i < m; i++){
      cin >> broken[i];  
      dp[broken[i]] = 0;
     }
    
    dp[n] = 1;
    for(int i = n-1; i >= 0; i--){
        if(dp[i] == 0){
            continue;
        }
        else{
            dp[i] = 0;
            if(i + 1 <= n){
                (dp[i] += dp[i+1]) %= mod;
            }
            if(i+2 <= n){
                (dp[i] += dp[i+2]) %= mod;
            }
            
        }
    }
    
    cout << dp[0] << endl;
    
    
    
    
    
}
