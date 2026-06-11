#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef pair<int, int> P;

struct edge {int to; ll cost; };

int dx[] = {-1, 1, 0,  0};
int dy[] = { 0, 0, 1, -1};

 
int main(){
  int n;
  cin >> n;
  set<int> st;
  for(int i=0; i<n; i++){
    int a;
    cin >> a;
    st.insert(a);
  }
  string ans;
  if(n==st.size()) ans = "YES";
  else ans = "NO";
  cout << ans << endl;
  return 0;
}
