#include <bits/stdc++.h>

using namespace std;

#define int long long
#define rep(i,a,n) for(int i = a; i<n; i++)
#define per(i,a,n) for(int i = n-1; i>=a; i--)

int max(int a,int b){return a>b ? a:b;}
int min(int a,int b){return a<b ? a:b;}


const int INF = 1e9+7;

int n,m,d;

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin>>n>>m>>d;
  int ctr = 0;
  rep(i,n,m+1){
    if(i%d == 0)ctr++;
  }
  cout<<ctr<<"\n";
}
