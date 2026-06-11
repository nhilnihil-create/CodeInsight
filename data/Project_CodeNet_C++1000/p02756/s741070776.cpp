#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
string s;
int q;
int cnt = 0;
bool is_front = true;

string solver() {
  deque<char> dq;
  for(char &c : s) dq.push_back(c);
  
  rep(i, q) {
    int m;
    cin >> m;
    if (m == 1) {
      is_front = !is_front;
      cnt++;
    } else {
      int f;
      char c;
      cin >> f >> c;
      if (f == 1) {
        if (!is_front) {
          dq.push_back(c);
        } else {
          dq.push_front(c);
        }
      } else {
        if (!is_front) {
          dq.push_front(c);
        } else {
          dq.push_back(c);
        }        
      }
    }
  }
  string ans = ""; 
  if (!is_front) {
    for(auto it = dq.rbegin(); it != dq.rend(); it++) {
      ans +=  *it;
    }
    return ans;
  } else {
    for(auto it = dq.begin(); it != dq.end(); it++) {
      ans += *it;
    }
    return ans;
  }
}

int main()
{
  cin >> s >> q;
  string a = solver();
  
  cout << a << endl;

 return 0;
}