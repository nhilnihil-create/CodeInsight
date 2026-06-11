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
int main()
{
	ll N,M;
	vector<pair<ll,ll>>V;
	cin>>N>>M;
	rep(i,M){
		ll t;
		char u;
		cin>>t>>u;
		V.push_back(make_pair(t,u));
	}
	ostringstream oss;
	oss<<102;
	rep(i,1000){
		ostringstream oss;
		oss<<i;
		bool F=true;
		if(oss.str().size()==N){
			rep(j,V.size()){
				//cout<<oss.str()<<" "<<oss.str()[V[j].first-1]<<" "<<F<<endl;
				if(oss.str()[V[j].first-1]!=V[j].second){
					F=false;
				}
			}
		}
		else F=false;
		if(F==true){
				cout<<i<<endl;
				return 0;
		}
	}
	cout<<"-1"<<endl;
}