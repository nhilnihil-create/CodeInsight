#include <bits/stdc++.h>

#define ll long long
#define FOR(i,n,m) for(int i=(int)(n); i<=(int)(m); i++)

using namespace std;

#define pow5(n) ((n)*(n)*(n)*(n)*(n))

int main()
{
  ll X; cin>>X;
  FOR(A,-120,120)FOR(B,-120,120){
    if (pow5(A)-pow5(B)==X){
      cout<<A<<" "<<B<<endl;
      return 0;
    }
  }
  return 0;
}