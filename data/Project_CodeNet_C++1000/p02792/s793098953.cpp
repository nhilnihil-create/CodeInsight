#include<bits/stdc++.h>
#define rep(i,a) for(int (i)=0; (i)<(a); (i)++)
#define rep2(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define MOD 1000000007
#define all(v) v.begin(), v.end()
#define m0(x) memset(x,0,sizeof(x))
#define chmax(a,b) if(b>a) a = b
#define chmin(a,b) if(b<a) a = b
#define LINF 1e9+10
typedef long long ll;

using namespace std;

int dx[] = {1,-1, 0, 0};
int dy[] = {0, 0,-1, 1};
ll table[10][10]; 

ll top(ll a){
      ll keta = 0, tmp = a;
      while(tmp > 0){
            tmp /= 10;
            keta++;
      }
      return ll(a/pow(10,keta-1));
}

int main(){
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
      ll n; cin >> n;

      rep(i,10)rep(j,10) table[i][j] = 0;
      
      rep2(i,1,n+1){
            ll t, b;
            t = top(i); b = i%10;
            table[t][b]++;
      }
      ll ans = 0;
      rep2(i,1,10)rep2(j,1,10){
            ans += table[i][j] * table[j][i];
      }

      cout << ans << endl;

      return 0;
}
