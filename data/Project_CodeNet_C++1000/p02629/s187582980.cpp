#include<bits/stdc++.h>
#include <string> 

using namespace std;
const long long INF = 1e18;
#define PI 3.141592653589793
#define REP(i, n) for(int i = 0;i < n;++i)
long long N,Y;
int A[1000000];
int main()
{
  cin>>N;
  for(Y=0;N!=0;Y++){
    N--;
    A[Y]=N%26;
    N/=26;
  }
  for(Y--;Y>=0;Y--)cout<<(char)(A[Y]+'a');
  return 0;
}