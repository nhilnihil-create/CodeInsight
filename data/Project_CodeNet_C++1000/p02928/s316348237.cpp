#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
//解説AC
int main() {
  int n;
  long long k;
  cin >>n>>k;
  vector<int>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  long long kotae=0;
  long long count=0;
  long long count2=0;
  //1セットのなかにある転倒数　入力例3だと43個
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      if(a[i] >a[j]){
        //cout<<a[i]<<" "<<a[j]<<endl;
        count++;
      }
    }
  }
  //他のセットと組み合わせてできる転倒数　入力例3だと45個
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(a[i] >a[j]){
        //cout<<a[i]<<" "<<a[j]<<endl;
        count2++;
      }
    }
  }
  //cout<<count<<" "<<count2<<endl;
  kotae+=count*k%MOD;//kセット分
  kotae%=MOD;
  kotae+=(k-1)*k/2%MOD*count2%MOD;//kセットから2つを選んだとき
  kotae%=MOD;  
  cout<<kotae<<endl;
  return 0;
}