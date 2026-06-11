#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  unordered_set<int> s;
  bool ok = true;
  for(int i=0; i<n; i++) {
    int x;
    cin >> x;
    if(s.count(x)) {
      ok = false;
    }
    s.insert(x);
  }
  
  puts(ok?"YES":"NO");
}