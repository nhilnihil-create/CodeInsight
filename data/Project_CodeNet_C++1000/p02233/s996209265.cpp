#include <iostream>
using namespace std;
int n;
int dp[45];
void fibonacci(int);
int main(){
  int result;
  cin >> n;
  dp[0]=1;
  dp[1]=1;
  if(n!=0&&n!=1)  fibonacci(2);
  cout << dp[n] << endl; 
  return 0;
}
void fibonacci(int i){
  dp[i]=dp[i-1]+dp[i-2];
  if(n==i) return ;
  fibonacci(i+1);
}