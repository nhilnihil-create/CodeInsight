#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll mod=1e9+7;

int main()
{
  int h1,m1,h2,m2,k;
  cin>>h1>>m1>>h2>>m2>>k;
  cout<<(h2-h1)*60+(m2-m1)-k<<endl;
}