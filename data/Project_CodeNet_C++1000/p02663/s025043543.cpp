#include<bits/stdc++.h>

#define ll long long
const int inf = 1e9+7;
const ll INF = 1e18+7;

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int h1,m1,h2,m2,k;
  cin >>h1>>m1>>h2>>m2>>k;
  int n1 = h1*60+m1;
  int n2 = h2*60+m2;
  cout<< n2-n1-k<<"\n";
}
