#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
 
#define bit(n,k) ((n>>k)&1) //*n no k bit me 1 or 0*/

const int mx=1000010;
const ll mod=1e9+7;

int main(){
  int n; 
  string s; 
  cin >> n >> s;
  vector<int> a(n);
  rep(i,n) a[i]=(int)(s[i]-'0');

  for(int i=0; i<min(10,n-1); i++){
    int k = a.size();
    for(int j=0; j<k-1; j++){
      a[j] = abs(a[j]-a[j+1]);
    }
    a.pop_back();
  }

  int m = a.size();
  if(m==1){ cout << a[0] << endl; return 0; }

  int cnt1=0, cnt2=0;
  bool flag = true;
  rep(i,m){
    if(a[i]==1){
      if(((m-1)&i)==i){
        cnt1++;
      }
      flag = false;
    }
    if(a[i]==2){
      if(((m-1)&i)==i){
        cnt2++;
      }
    }
  }
  if(flag){
    cout << cnt2%2*2 << endl;  
    return 0;  
  }
  cout << cnt1%2 << endl;
  return 0;
}