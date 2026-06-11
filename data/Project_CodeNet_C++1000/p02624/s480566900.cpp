#include <bits/stdc++.h>
#define  ENDL  '\n'
#define N 10000007
using namespace std;
typedef unsigned long  long int ulli;
bool prime[N];
ulli cantdiv[N];
void primos();
int main()
{
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  ulli resp=1;
  cin>>n;
  primos();
  for(int i=2; i<=n;  ++i)
  {
    resp+=(cantdiv[i]+2)*i;
  }
  cout<<resp;
  return 0;
}

void primos()
{
  for(int i=2; i<=N/2; ++i)
  {
    for(int j=i*2; j<N; j+=i)
    {
      cantdiv[j]++;
    }
  }
  cantdiv[1]=1;
  return;
}
