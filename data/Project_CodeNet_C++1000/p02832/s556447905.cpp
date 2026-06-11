#include <bits/stdc++.h>
#include<algorithm>	
using namespace std;
#define ll long long 
vector<vector<int>> l(100001);
//int used[100001][100001];
int col[100001];
const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];


int main() {
  int n;
  cin >> n;
  int a[n+1];
  
  for(int i= 1;i<n+1;i++){
    cin >> a[i];
  }
  int b = 0;
  int t = 1;
  for(int i= 1;i<n+1;i++){
      if(a[i] == t){
        t += 1;
      }else{
        b += 1;
      }
    
  }
  
  if(t == 1){
    cout << -1;
  }else{
    cout << b;
  }
  
  
}


