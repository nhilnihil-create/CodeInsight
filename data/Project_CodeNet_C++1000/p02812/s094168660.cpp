#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
  
void f(int n) {
  string s;
  cin >> s;
  int count = 0;
  
  forn(i, n-2){
  	if(s[i] == 'A')
      if(s[i+1] == 'B')
        if(s[i+2] == 'C')
          count++;
  }
  cout << count << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  f(n);
  return 0;
}