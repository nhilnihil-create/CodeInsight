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
  ll n,k; cin >> n >> k;
  int keta = 0;
  while(n>0){
    n/=k;
    keta++;
  }
  cout << keta;
  return 0;
}