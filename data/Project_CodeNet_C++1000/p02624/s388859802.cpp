#include<bits/stdc++.h>
using namespace std;

static long long int ans[10000001];

int main(){
  long long n;
  cin >> n;
  
  for(int i=1;i<=n;i++){
    for(int j=i;j<=n;j+=i){
      ans[j]++;
    }
  }
  
  long long sum = 0;
  for(int i=1;i<=n;i++){
    sum += i * ans[i];
  }
  cout << sum << endl;
}