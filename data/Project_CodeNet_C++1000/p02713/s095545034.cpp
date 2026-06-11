#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i= 1;i<n+1;i++)

int gcd(int a,int b){
  while(true){
    int temp = b;
    b = a % b;
    a = temp;
    if(b==0) return a;
    if(b==1) return b;
  }
}

int ans(int a, int b ,int c){
  int maximum = max(gcd(a,b),gcd(a,c));
  int minimum = min(gcd(a,b),gcd(a,c));
  return gcd(maximum,minimum);
}

int main(){
  int x;
  cin >> x;

  int cnt = 0;
  rep(i,x){
    rep(j,x){
      rep(k,x){
        int I = max(i,max(j,k));
        int K = min(i,min(j,k));
        int J = i+j+k-I-K;
        cnt += ans(I,J,K);
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
