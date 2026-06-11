#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<ll,int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n;
  cin >> n;
  vector<P> a;
  for(int i=1; i<=n; i++){
    int k;
    cin >> k;
    a.push_back(make_pair(k, i));
  }
  sort(a.begin(), a.end());
  for(int i=0; i<n; i++){
    if(i==n-1) cout << a[i].second << endl;
    else cout << a[i].second << " ";
  }
  return 0;
}
