#include<iostream>
using namespace std;

int main(){

  int n;

  cin >> n;

  long long int a[n];

  for(int i=0; i<n; i++){
    cin >> a[i];
  }

  long long int dp[n];

  dp[0] = a[0];

  int count = 0;

  for(int i=1; i<n; i++){
    if(dp[count] < a[i]){
      dp[++count] = a[i];
    }
    else{
      for(int j=0; j<n; j++){
        if(dp[j] >= a[i]){
          dp[j] = a[i];
          break;
        }
      }
    }
  }

  cout << count + 1 << endl;




  return 0;
}