#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef pair<int, int> ii; 

char s[4010]; 
int n; 

int main() {
  scanf("%d", &n); 
  scanf(" %s", s); 
  ll r = 0, g = 0, b = 0; 
  for(int i = 0; i < n; ++i) {
    r += s[i] == 'R'; 
    g += s[i] == 'G'; 
    b += s[i] == 'B'; 
  }

  ll ans = r * g * b; 
  for(int i = 0; i < n; ++i) {
    for(int j = 1; i + 2 * j < n; ++j) {
      set<int> st({s[i], s[i + j], s[i + 2 * j]}); 
      ans -= st.size() == 3; 
    }
  }
  printf("%lld\n", ans); 
}
