#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FORL(i,x) for(int i=head[x];i;i=nxt[i])
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define PB push_back
#define MP make_pair
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll gcd(ll x, ll y)
{
    ll temp;
    while (y != 0) {
        temp = y;
        y = x % y;
        x = temp;
    }
    return (x);
}


int main() {
  int n; cin >> n;
  int a[n];
  vector<int> v1;
  vector<int> v2;
  int zerocnt = 0;

  FOR(i,0,n-1) cin >> a[i];
  sort(a,a+n);
  
  FOR(i,0,n-1) {
    
    if(a[i]<0){
      v2.PB(a[i]);
    }
    if(a[i]>=0){
      v1.PB(a[i]);
    }
    // if(a[i]==0) ++zerocnt;
  }

  

  // if(SZ(v1)==0 && SZ(v2)==0){
  //   cout << 0 << endl;
  //   FOR(i,0,n-2){
  //     cout << "0 0" << endl;
  //   }
  //   return 0;
  // }
  // else if(SZ(v1)==1 && SZ(v2)==0){
  //   cout << v1[0] << endl;
  //   FOR(i,0,n-2){
  //     cout << v1[0] << " 0" << endl;
  //   }
  //   return 0;
  // }
  // else if(SZ(v2)==1 && SZ(v1)==0){
  //   cout << -v2[0] << endl;
  //   cout << "0 " << v2[0] << endl;
  //   if(n>2){
  //     FOR(i,0,n-3){
  //       cout << -v2[0] << " 0" << endl;
  //     }
  //   }
  //   return 0;
  // }
  if(SZ(v1)==0){
    v1.PB(v2[SZ(v2)-1]);
    v2.pop_back();
  }
  else if(SZ(v2)==0){
    v2.PB(v1[0]);
    v1.erase(v1.begin());
  }

  FOR(i,0,zerocnt-1){
    v1.PB(0);
  }

  int sum = 0;

  FOR(i,0,SZ(v1)-1) {
    // cout << v1[i] << endl;
    sum += v1[i];
  }
  FOR(i,0,SZ(v2)-1) {
    // cout << v2[i] << endl;
    sum -= v2[i];
  }
  cout << sum << endl;

  if(SZ(v1)>1){
    int sizev1 = SZ(v1);
    int sizev2 = SZ(v2);
    FOR(i,1,sizev1-1){
      cout << v2[sizev2-1] << " " << v1[sizev1-i] << endl;
      v2[sizev2-1] -= v1[sizev1-i];
      v1.pop_back();
    }
  }

  int sizev2 = SZ(v2);
  int ref = 1;
  while(!v2.empty()){
    cout << v1[0] << " " << v2[sizev2-ref] << endl;;
    v1[0] -= v2[sizev2-ref];
    v2.pop_back();
    ++ref;
  }

}

