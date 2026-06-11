#include<bits/stdc++.h>
using namespace std;
#define INFTY 10000000000
typedef long long int ll;
const int MOD=1000000007;
using Graph = vector<vector<int>>;
using ipair = pair<ll,ll>;
bool operator< (const ipair a, const ipair b){return a.first < b.first;};
#define rep(i,n) for (int i = 0; i < (n); ++i)
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){
  int n;
  cin>>n;
  int cnt=0;
  vector<int> a(n+1);
  for(int i=1;i<=n;i++)cin>>a[i];
  vector<int> ball(n+1,0);
  for(int i = n;i>0;i--){
    int num = n/i;
    int balls=0;
    for (int j = 1; j <= num; j++)
    {
      if(ball[i*j]==1)balls++;
    }
    if(balls%2==a[i])ball[i]=0;
    else{ ball[i] = 1; cnt++;}
  }
  cout<<cnt<<endl;
  for(int i=1;i<=n;i++){
    if(ball[i]==1)cout<<i<<" ";
  }

  return 0;
}