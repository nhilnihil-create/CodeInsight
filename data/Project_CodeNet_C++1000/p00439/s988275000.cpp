#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,n) for(i=a;i<n;i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef pair<int,int> pii;

int main(void) {
  int i,j;
  int n,k;
  while(1){
    cin>>n>>k;
    if(n==0 && k==0)break;
    vi v(n+1);
    v[0]=0;
    rep(i,n)
      cin>>v[i+1];
    rep(i,n)
      v[i+1]+=v[i];
    int ans=-INF;
    loop(i,k,n+1)
      ans=max(ans,v[i]-v[i-k]);
    cout<<ans<<endl;
  }
}