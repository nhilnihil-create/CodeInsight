#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++) 
#define rep(i,n); for(int i = 0; i < (n); i++)
#define chmin(a,b) if((a)>(b)) (a)=(b); 
#define chmax(a,b) if((a)<(b)) (a)=(b);
#define vi vector<int>
int gcd(int a,int b){/*a>=0,b>=0,￢(a=b=0)*/
  while(min(a,b)>0){if(a<b)swap(a,b);a=a%b;}return max(a,b);
}
int dx[]={0,1,0,-1,1,-1,-1,1};
int dy[]={1,0,-1,0,1,1,-1,-1};
const int MOD = 1e9+7;
const int INF = 1e18+10;

/*----------------------------------------------*/
vi to[101010];

signed main(){
  int n;
  cin>>n;
  int check=0;
  rep(i,n){
    int a;
    cin>>a;
    check^=a;
  }

  if(check==0) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;

  return 0;
}