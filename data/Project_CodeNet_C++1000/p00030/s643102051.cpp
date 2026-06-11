#include <bits/stdc++.h>

#define REP( i, n) for( int i = 0; i < (n); ++i)
#define FOR( i, a, b) for( int i = (a); i < (b); ++i)

using namespace std;

int n;
int s;
int ans;
int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int dfs( int x, int i, int sum){

  if( x == n && sum == s){
    ++ans;
  }else{
    if( i < 10){
      dfs( x+1, i+1, sum+a[i]);
      dfs( x, i+1, sum);
    }else{
      return ans;
    }
  }
}

int main(){

  while(1){
    ans = 0;
    cin >> n >> s;
    if( n == 0 && s == 0){
      break;
    }

    cout << dfs( 0, 0, 0) << endl;
  }
  return 0;
}