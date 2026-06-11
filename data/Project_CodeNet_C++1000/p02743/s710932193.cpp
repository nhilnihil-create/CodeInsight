#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define MOD 1000000007ULL;
#define rep(i,n) for(int i=0;i<n;i++)


int main() {
  	long double a,b,c;
  	cin>>a>>b>>c;
  	
  	if(a+b<c && 4*a*b<(c-a-b)*(c-a-b)) cout<<"Yes"<<endl;
  	else cout<<"No"<<endl;
  
}