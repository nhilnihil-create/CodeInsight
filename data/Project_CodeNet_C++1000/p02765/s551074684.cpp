#include<bits/stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define vpll vector<pair<ll,ll>>
#define pii pair<int,int>
#define rep(i,a) for(int (i)=0; (i)<(a); (i)++)
#define rrep(i,a) for(int (i)=a-1; (i)>=(0); (i)--)
#define rep2(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
#define m0(x) memset(x,0,sizeof(x))
typedef long long ll;

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,r; cin >> n >> r;
  int keta = 0;
  if(n >= 10) cout << r << endl;
  else{
    cout << r + 100*(10 - n) << endl; 
  }
  return 0;
}
