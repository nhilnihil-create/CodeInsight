#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

typedef long long ll;
ll dp[11451419];

int main(){
  int n, m;
  cin>> n >> m; 
  vector <int> a(n);
  vector<bool> ok(n+1, true);
  for(int i=0; i<m; i++) {
    cin>> a[i];
    ok[a[i]]=false;
  }
  dp[0]=1;
  for(int i=1; i<=n; i++){
    if(ok[i]){
	if(i==1)dp[i]=1;
	else{
	  dp[i] = (dp[i-1]+dp[i-2])%MOD;
	}
    }
  } 
  cout<< dp[n] << endl;
}
