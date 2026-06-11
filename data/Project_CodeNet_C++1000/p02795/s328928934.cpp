#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define All(a) a.begin(),a.end()
#define INF 1000000007
const int MOD = 1000000007;
//accumulate(vec.begin(), vec.end(), 0)

int gcd(int x,int y){
  if(x%y==0) return y;
  else return gcd(y,x%y);
}

int main(){
  int h,w,n;
  cin >> h >> w >> n;
  int black_cnt=0;
  int ans = 0;
  while(n>black_cnt){
    black_cnt += max(h,w);
    ans ++;
  }
  cout<< ans <<endl;
}
