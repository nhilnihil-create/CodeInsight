#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool prime[200000000]={};
void Eratosthenes(int n)
{
  for(int i=2;i<=(int)sqrt(n)+1;++i)
  {
    if(prime[i]==true)
    {
      for(int j=i*2; j<=n; j+=i)
      {
        prime[j]=false;
      }
    }
  }
}

int main()
{ 
  int n;
  vector<int> ans;
  while(cin>>n, n)
  {
    for(int i=2;i<=2*n;++i) prime[i]=true;
    Eratosthenes(2*n);
    int cnt=0;
    for(int i=n+1;i<=2*n;++i) if(prime[i]==true) cnt++;
    ans.push_back(cnt);
  }
  for(auto& e:ans) cout<<e<<"\n";

  return 0;
}

