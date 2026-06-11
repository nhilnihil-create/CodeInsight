#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define int long long 

int ans[510][510];

void dfs(int left, int right, int val){ 
  
  if( right - left == 1 ){ 
    return ;
  }
    
  // 半開区間[left,right)
  
  int mid = (left+right)/2;
  
    for(int i = left; i < mid; i++){ 
      for(int j = mid; j < right; j++){
        ans[i][j] = val; ans[j][i] = val;
      }
    }
  
    dfs(left,mid,val+1); dfs(mid,right,val+1);
  
}



signed main(void){ 
  
  int N; cin >> N; 
  
  dfs(0,N,1); // (今見ているサイズ / 持っている値) 
  
  
  for(int i = 0; i < N; i++){
    for(int j = i+1; j < N; j++){ 
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  
  return 0;
}