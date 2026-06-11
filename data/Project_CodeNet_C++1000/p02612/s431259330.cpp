#include<bits/stdc++.h>
using namespace std;
int main()
{
  int64_t n;
  cin>>n;
  cout<< (n%1000?1000-n%1000:0);
  return 0;
}
