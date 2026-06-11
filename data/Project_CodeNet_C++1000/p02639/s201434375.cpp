#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c, d, e;
  cin>>a>>b>>c>>d>>e;
  vector<int> vect;
  vect.push_back(a);
  vect.push_back(b);
  vect.push_back(c);
  vect.push_back(d);
  vect.push_back(e);
  for (int i = 0; i < vect.size(); i++)
  {
    if (vect[i] == 0)
    {
      cout<<i+1;
      return 0;
    }
  }
}
