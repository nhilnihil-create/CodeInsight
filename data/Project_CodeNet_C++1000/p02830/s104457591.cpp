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
  string s, t;
  cin >> s >> t;
  for(int i=0; i<n; i++){
    cout << s[i] << t[i];
  }
  cout << endl;
  return 0;
}
