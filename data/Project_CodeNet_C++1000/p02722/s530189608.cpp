#include<iostream>
using namespace std;
typedef long long li;
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }

int f(li n,li k){
  while(n>=k){
    if(n%k==0)n/=k;
    else n%=k;
  }
  if(df)print("->",n);
  return n==1;
}

int main(){
  li n; cin >>n;
  li cnt=0;
  if(n==2){
    print(1);
    return 0;
  }
  for(li i=2;i*i<=n;i++){
    if(n%i==0){
      if(df)print(n,i,n/i);
      cnt+=f(n/i,i);
      if(df)print(cnt);
    }
    if((n-1)%i==0){
      if(df)print(n-1,i,n/i);
      cnt+=2-(i*i==n-1);
      if(df)print(cnt);
    }
  }
  print(cnt+2);                 // k=n-1,n
}
