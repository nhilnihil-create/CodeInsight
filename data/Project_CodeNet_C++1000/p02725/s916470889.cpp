#include<bits/stdc++.h>
using namespace std;
int main(){
  int e,b;
  cin >> e >> b;
  int a[b+1]={0};
  for(int i=0;i<b;i++){
    cin >> a[i];
  }
  int sum=(e-a[b-1])+a[0];
  int m;
  
  for(int i=0;i<b;i++)sum=max(sum,a[i+1]-a[i]);
  cout << e-sum << endl;
}
  
