#include<bits/stdc++.h>
using namespace std;
//using ll=long long;
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
  vector<int>s = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
  int k;
  cin >> k;
  cout<< s[k-1] <<endl;
}
