#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	ll N;
	cin >> N;
	vector<ll> A(N);
	vector<ll> backet(N);	
  for(ll i=0;i<N;i++){
    ll tmp=0;
	cin >> tmp;
    tmp--;
    A[i]=tmp;
    	backet[tmp]=i;
	}
  for(ll i=0;i<N;i++){
    cout << backet[i]+1 << endl;
  }
}