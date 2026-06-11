#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<ll, ll>P;
ll N;
ll memo=1;
void num(vector<P> &a, ll x, ll g,ll h){
	if(x==N){return;}
	auto z=a[x];
    if(z.first>=h){::memo++;num(a,x+1,z.first,z.second);}
  	else if(z.second<h){num(a,x+1,z.first,z.second);}
    else{num(a,x+1,g,h);}
}

int main(){
  cin>>N;
  vector<ll>X(N);
  vector<ll>L(N);
  vector<P>A(N);
  rep(i,N){
  	cin>>X[i]>>L[i];
  	ll p=X[i]-L[i];
  	ll q=X[i]+L[i];
  	A[i]=P(p,q);
  }
  sort(A.begin(),A.end());
  auto t=A[0];
  ll a01=t.first,a02=t.second;
  num(A,1,a01,a02);
  cout<<memo;
}