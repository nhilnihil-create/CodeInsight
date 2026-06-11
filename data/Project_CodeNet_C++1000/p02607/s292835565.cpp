#include <bits/stdc++.h>

using namespace std;

#define int long long
#define rep(i,a,n) for(int i = a; i<n; i++)
#define per(i,a,n) for(int i = n-1; i>=a; i--)

int max(int a,int b){return a>b ? a:b;}
int min(int a,int b){return a<b ? a:b;}


const int INF = 1e9+7;

int n,in[100];


signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin>>n;
  int res = 0;
  rep(i,1,n+1){

    cin>>in[i-1];
    if(i%2 == 1 && in[i-1] % 2 == 1)res++;
  }
  cout<<res<<"\n";


}
