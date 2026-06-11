#include<functional>
#include<algorithm>
#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define all(v) (v).begin(),(v).end()
#define pf push_front
#define pb push_back
#define int long long
using namespace std;
const int INF=1000000007;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int f[50]={};

int fib(int n){
  if(n==0||n==1)return f[n]=1;
  if(f[n]!=0)return f[n];
  return f[n]=fib(n-1)+fib(n-2);
}

signed main(){
  int n;
  cin>>n;
  cout<<fib(n)<<endl;

  return 0;
}