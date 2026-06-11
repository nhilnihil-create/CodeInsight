#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<ll,int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};
 
int main(){
  int n, k;
  cin >> n >> k;
  set<int> st;
  for(int i=0; i<k; i++){
    int d;
    cin >> d;
    for(int j=0; j<d; j++){
      int a;
      cin >> a;
      st.insert(a);
    }
  }
  int ans = n - st.size();
  cout << ans << endl;
  return 0;
}
