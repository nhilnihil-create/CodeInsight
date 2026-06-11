#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct BIT{
private:
  vector<T> A;
  const int n;
  
public:
  BIT(int _n) : A(_n+1,0), n(_n){}
  
  T sum(int i){
    T s=0;
    while(i>0){
      s+=A[i];
      i-=i&-i;
    }
    return s;
  }
  
  T sum(int i,int j){
    return sum(j)-sum(i-1);
  }
  
  void add(int i,T x){
    while(i<=n){
      A[i]+=x;
      i+=i&-i;
    }
  } 
};

int main(){
  int n,q;
  cin>>n>>q;
  
  ll c,x,y;
  BIT<ll> bit(n);
  
  rep(i,n){
    cin>>x;
    bit.add(i+1,x);
  }
  
  rep(i,q){
    cin>>c>>x>>y;
    if(c==0) bit.add(x+1,y);
    else cout<<bit.sum(x+1,y)<<endl;
  }
   
  return 0;
}