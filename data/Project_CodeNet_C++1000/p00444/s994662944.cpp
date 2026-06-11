#include<iostream>
#include<algorithm>
#include<cstring>
#define INF 1<<28
using namespace std;

int memo[10000];

int solve(int n){

  int res = INF;
  if(!n) return 0;
  if(n < 0) return INF;
  if(memo[n]) return memo[n];

  return memo[n] = res = min(res, min(solve(n-500), min(solve(n-100), min(solve(n-50), min(solve(n-10), min(solve(n-5), solve(n-1)))))) +1);
}

int main(){

  int n;
  while(cin >> n, n){
    memset(memo, 0, sizeof(memo));
    cout << solve(1000-n) << endl;
  }

}