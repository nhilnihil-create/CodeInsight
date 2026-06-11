#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <istream>
#include <sstream>
#include <cctype>
#include <iomanip>
//cout << fixed << setprecision(20) << *** << endl;
#define rep(i,N) for(int i=0;i<(int)N;++i)
typedef long long ll;
using namespace std;

double kitaichi(ll N){
	double d=0,t;
	for(ll i=1;i<=N;i++){
		t=i/(double)N;
		d=d+t;
	}
	return d;
}

int main()
{
	ll N,K,t;
	double ANS=0;
	vector<ll>Dice;
	vector<pair<ll,ll>>V;
	cin>>N>>K;
	rep(i,N){
		cin>>t;
		Dice.push_back(t);
	}
	rep(i,N-K+1){
		ll t=0;
		rep(j,K){
			t=t+Dice[i+j];
		}
		V.push_back(make_pair(t,i));
	}
	sort(V.begin(),V.end());
	rep(i,K){
		ANS=ANS+kitaichi(Dice[V.back().second+i]);
	}
	cout << fixed << setprecision(20) << ANS << endl;
}