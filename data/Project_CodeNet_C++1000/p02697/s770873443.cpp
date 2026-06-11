#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
//#define INF 1e18
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int n,m;

int main(){
  cin >> n >> m;
  vector<P> v;
  int l = 1;
  int r = (n+1)/2;
  while(r>l){
    v.push_back(P(l,r));
    l++;r--;
  }
  l = (n+1)/2;
  l++;
  r=n;
  if(n%2==0)r--;
  while(r>l){
    v.push_back(P(l,r));
    l++;r--;
  }
  rep(i,0,m){
    cout << v[i].first << " " << v[i].second << endl;
  }
  return 0;
}
