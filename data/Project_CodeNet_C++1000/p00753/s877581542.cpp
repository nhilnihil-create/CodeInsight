#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define LOOP(i,x,n) for(int i=x;i<n;i++)
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define MP make_pair
#define FR first
#define SC second
#define int long long
using namespace std;
const int MOD=1000000007;
const int INF=1000000009;

vector<int> prime;

bool Is_Prime(int n){
  if(n==1) return false;
  else if(n==2)return true;
  else if(n%2==0)return false;
  for(int i=3;i*i<=n;i+=2){
    if(n%i==0)return false;
  }
  return true;
}

signed main(){
  LOOP(i,1,250000)if(Is_Prime(i))prime.PB(i);
  int n;
  while(cin>>n,n){
    int m=n*2;
    cout<<lower_bound(ALL(prime),m+1)-upper_bound(ALL(prime),n)<<endl;
  }


  return 0;
}

