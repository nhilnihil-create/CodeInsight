#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end() 
#define size(x) ll(x.size())
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
  int n,cnt=0;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    string s;
    s = to_string(i);
    if(s.length () % 2 == 1) {
      cnt++;
    }
  }
  cout << cnt << endl;
}