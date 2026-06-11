#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;

  int N = (1 << n);
  vector<int> s(N);
  
  for(int i = 0; i < N; i++) cin >> s[i];

  sort(s.begin(),s.end(),greater<ll> ());
  //for(int i = 0; i < N; i++) cout << s[i] << endl;

  vector<int> ans;
  ans.push_back(s[0]);
  s[0] = -1;

  for(int i = 0; i < n; i++) {
      int pos = 0;
    vector<int> p = ans;
    sort(p.begin(),p.end());
    //  for(int l = 0; l < p.size(); l++) cout << p[l] << endl;
    // cout << endl;
 
    while(p.size() && pos < N) {
    
      if(s[pos] == -1) {
	pos++;
	continue;
      }

      if(s[pos] <  p.back()) {
	ans.push_back(s[pos]);
	s[pos] = -1;
	p.pop_back();
      }
      pos++;
    }
    if(p.size() > 0) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}

  
  

  
