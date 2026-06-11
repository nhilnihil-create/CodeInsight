#include <bits/stdc++.h>
#define Rep(i,j,n) for(int i=j; i<n; i++)
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100//000000000
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<int,P>
#define T tuple<int,int,int> 
using namespace std;

int main(){
  int m; cin >> m;
  ll ans=0;
  ll keta=0;
  rep(i,m){
    ll d,c; cin >> d >> c;
    ans+=d*c;
    keta+=c;
  }

  cout << (ans-1)/9+keta-1 << endl;
  return 0;
}
/*
-9 0
10-18 1
19-27 2
28-36 3
37-45 4 

9874
1774
874
154
64
10
1

*/