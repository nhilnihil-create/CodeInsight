#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin>>s;
  int n=s.size()+1;
  //num[i]はa[i+1]の左にある＜と右にある＞が連続する数の最大値
  vector<int>num(n);
  //左の＜について
  int left=0;
  for(int i=1;i<n;i++){
    if('<'==s[i-1]){
      left++;
      num[i]=left;
    }
    else{
      left=0;
      num[i]=left;
    }
  }
  //右の＞について
  int right=0;
  for(int i=1;i<n;i++){
    if('>'==s[n-1-i]){
      right++;
      num[n-1-i]=max(right,num[n-1-i]);
    }
    else{
      right=0;
      num[n-1-i]=max(right,num[n-1-i]);
    }
  }
  //答え求める
  long long ans=0;
  for(int i=0;i<n;i++) ans+=num[i];
  cout<<ans<<endl;
}