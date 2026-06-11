#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <functional>

using namespace std; using ll=long long; using ld=long double; using P=pair<ll,ll>; const int INF=1e9; const ll LINF=1e18;
template<typename T> void caut(T a, T b, T c){cout<<"("<<a<<","<<b<<","<<c<<") ";}
template<typename T> void caut(T a, T b){cout<<"("<<a<<","<<b<<") ";}
template<typename T> void caut(T a){cout<<"("<<a<<") ";}

int main(){
  int n; cin>>n;
  int an=n+1;
  an-=2;
  if (n%2==0) an--;
  cout<<an/2<<endl;
}