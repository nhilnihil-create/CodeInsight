#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define Int int64_t
const Int MOD=998244353;
using namespace std;

Int N,K,M,A,B;
int main()
{
  cin>>A>>B>>N;
  N=min(N,B-1);
  cout<<((A*N)/B)-(A*(N/B))<<"\n";
}