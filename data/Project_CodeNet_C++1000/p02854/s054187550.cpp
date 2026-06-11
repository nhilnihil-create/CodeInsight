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
	ll N,sum=0;
	cin>>N;
	vector<ll>V;
	vector<ll>ANS;
	rep(i,N){
		ll t;
		cin>>t;
		sum=sum+t;
		V.push_back(sum);
	}
	rep(i,N-1){
		ll t;
		t=abs(V[i]-(V.back()-V[i]));
		ANS.push_back(t);
	}
	sort(ANS.begin(),ANS.end());
	cout<<ANS.front()<<endl;
}