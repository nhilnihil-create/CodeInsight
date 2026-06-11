
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
using vvll = vector<vector<ll>>;
using vll = vector<ll>;
const ll MOD=9998903;


ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

void solve() {
	ll i,j,count;
    ll N;
    cin>>N;
    vector<ll> A(N,0);
    vector<ll> exist(1001000,0);
	ll gcd=0;
	for(i=0;i<N;i++){
		cin>>A[i];
		gcd=GCD(gcd,A[i]);
		exist[A[i]]++;
	}
	for(i=2;i<=1000000;i++) {
		count=0;
		for(j=i;j<=1000000;j+=i) count+=exist[j];
		if(count>=2) break; //被りがあったら
	}
	if(i==1000001) {//被りがなければiは1000001となる
		cout<<"pairwise coprime"<<endl;
		return;
	}
	if(gcd==1) {
		cout<<"setwise coprime"<<endl;
	}
	else {
		cout<<"not coprime"<<endl;
	}
}


int main()
{
    solve();
    return 0;
}