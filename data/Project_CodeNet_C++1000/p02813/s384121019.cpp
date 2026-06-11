#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;cin>>n;
  vector<int> p(n), q(n);
  for (auto &&i : p)
  {
    cin>>i;
  }
  for (auto &&i : q)
  {
    cin>>i;
  }
  vector<int> perm(n);
  for (size_t i = 0; i < n; i++)
  {
    perm[i] = i+1;
  }
  int tmp1,tmp2,cnt=1;
  do
  {
    if (q == perm)
    {
      tmp1 = cnt;
    }
    if (p == perm)
    {
      tmp2 = cnt;
    }
    cnt++;
    
  } while (next_permutation(perm.begin(),perm.end()));
  cout << abs(tmp2 - tmp1) << endl;
  
  
  
}