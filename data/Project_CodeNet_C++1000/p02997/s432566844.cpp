#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<ll>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  int n,k;
  cin >> n >> k;
  if(k>(n-2)*(n-1)/2){
    cout << -1 << endl;
    return 0;
  }
  //vector<vector<int>> v(n,vector<int>(n,0));
  Graph v(n);
  rep(i,n-1){
    v[0].push_back(i+1);
  }
  int left=1;
  int right=2;
  cout << n-1+(n-2)*(n-1)/2-k << endl;
  while(k!=(n-2)*(n-1)/2){
    k++;
    v[left].push_back(right);
    if(right<n-1)right++;
    else{
      left++;
      right=left+1;
    }
  }
  rep(i,n){
    for(int h: v[i]){
      cout << i+1 << " " << h+1 << endl;
    }
  }
}   
