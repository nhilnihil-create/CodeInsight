#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int main(){
  int x, n;
  cin >> x >> n;
  /*
  vector<int> p(n);
  vector<int> orip(n);
  rep(i, n){
    int inp;
    cin >> inp;
    orip[i]=inp;
    if(inp-x>=0){
      p[i]=inp-x;
    } else {
      p[i]=x-inp;
    }
  }
  sort(p.begin(), p.end());
  int ans=-1;
  int prep=-1;
  rep(i, n){
    if(p[i]-prep>=2){
      ans=p[i]-1;
    }
    prep=p[i];
  }
  if(ans==-1){
    ans=p[n-1]+1;
  }
  int minans=x-ans, maxans=x+ans;
  bool minok=true;
  rep(i, n){
    if(minans==orip[i]){
      minok=fakse;
      break;
    }
  }
  if(minok){
    cout << minans << endl;
    return 0;
  }
  */
  int inp;
  vector<int> count(1005);
  rep(i, n){
    cin >> inp;
    count[inp]++;
  }
  if(count[x]==0){
    cout << x << endl;
  } else {
    int xr=x, xl=x;
    while(1){
      xr++;xl--;
      if(xl>=0 && count[xl]==0){
        cout << xl << endl;
        return 0;
      } else if(xr<=101 && count[xr]==0){
        cout << xr << endl;
        return 0;
      }
    }
    /*
    if(xr>100 && xl<=0){
      if(abs(x)<=abs(x-101)){
        cout << 0 << endl;
      } else {
        cout << 101 << endl;
      }
    }
    */
  }
  return 0;
}
