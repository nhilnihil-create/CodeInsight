#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P=pair<int,int>;
using ll=long long;

int main() {
  int n;
  cin >> n;
  double ans=0;
  vector<int> whex(n),whey(n);
  rep(i,n) cin >> whex[i] >> whey[i];
  vector<int> v(n);
  rep(i,n) v[i]=i;
  do{
    int nowx=whex[v[0]],nowy=whey[v[0]];
    for(int i=1;i<n;i++){
        int x=whex[v[i]],y=whey[v[i]];
        double dist=sqrt((x-nowx)*(x-nowx)+(y-nowy)*(y-nowy));
        ans += dist;
    }
  }while(next_permutation(v.begin(),v.end()));
  double cut=1;
  rep(i,n){
      cut*=(i+1);
  }
  double fans=ans/cut;
  cout << fixed << setprecision(10);
  cout << fans << endl;
}

