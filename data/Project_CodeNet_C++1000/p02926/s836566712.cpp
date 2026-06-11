#include<bits/stdc++.h>
#define mod 1000000007
#define mod998 998244353
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define mkp make_pair
typedef long long ll;
using namespace std;

int N,x[100],y[100];
vector<pair<double,pair<int,int>>>v;
double res;

int main(){
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>x[i]>>y[i];
		v.push_back(mkp(atan2(y[i],x[i]),mkp(x[i],y[i])));
		v.push_back(mkp(atan2(y[i],x[i])+2*3.14159265358979323846264338,mkp(x[i],y[i])));
	}
	sort(v.begin(),v.end());
	for(int i=0;i<N*2;++i){
		double cx,cy;
		cx=cy=0;
		for(int j=i;j<N*2&&j<i+N;++j){
			cx+=v[j].second.first;
			cy+=v[j].second.second;
			res=max(res,sqrt(cx*cx+cy*cy));
		}
	}
	printf("%.15f\n",res);
}
