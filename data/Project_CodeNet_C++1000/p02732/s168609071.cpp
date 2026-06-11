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

ll XC2(ll a){
	return a*(a-1)/2;
}

int main()
{
	ll N;
	map<ll,ll>mp;
	vector<ll>V;
	cin>>N;
	rep(i,N){
		ll t;
		cin>>t;
		V.push_back(t);
		if(mp.count(t)==0)mp[t]=1;
		else mp[t]++;
	}
	ll Count=0;
	auto iter = mp.begin();
	for(iter;iter!=mp.end();iter++){
		Count=Count+XC2(iter->second);
	}
	rep(i,V.size()){
		ll ANS=Count;
		ANS=ANS-XC2(mp[V[i]]);
		ANS=ANS+XC2(mp[V[i]]-1);
		cout<<ANS<<endl;
	}
}