#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (in i = 0; i < (in)(n); i++)
const double PI=3.14159265358979323846;
const int64_t waru = 1000000007;
const in INF=1<<30;
#define vecvec(a,y,x) vector<vector<int>> a(y,vector<int>(x))
#define vec(a,n) vector<int> a(n);rep(i,n)cin>>a[i]

int main(){
vec(a,2);
  cin>>a[0]>>a[1];
  int sum =0;
  rep(i,2){
    int x=a[i];
    if(x==3) sum+=100000;
    if(x==2) sum+=200000;
    if(x==1) sum+=300000;
  }
  if(sum==600000) sum+=400000;
  cout<<sum;
}