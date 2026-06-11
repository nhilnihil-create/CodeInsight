#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(){
  int n, p;
  cin >> n >> p;
  vector<long long> s(n);
  for(int i=0;i<n;i++){
    char x;
    cin >> x;
    s[i] = x - '0';
  }
  vector<long long> x(p);
  x[0]+=1;
  long long amount=0, ans=0;
  //pで割ったあまりが同じものをカウント
  if(p==2){
    for(int i=0;i<n;i++){
      if(s[i]%2==0){
        ans += i+1;
      }
    }
  }else if(p==5){
    for(int i=0;i<n;i++){
      if(s[i]%5==0){
        ans += i+1;
      }
    }
  }else{
    int y=1;
    for(int i=0;i<n;i++){
      if(i!=0) y=y*10;
      y = y%p;
      amount += y*s[n-i-1];
      //cout << amount << endl;
      amount=amount%p;
      x[amount] += 1;
    }
    for(int i=0;i<p;i++){
      if(x[i]>1) ans += x[i]*(x[i]-1)/2;
    }
  }
  cout << ans << endl;
}
