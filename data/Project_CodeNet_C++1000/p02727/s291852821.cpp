#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

using namespace std;

#define fori(x) for (int i = 0; i < x; ++i)
#define forj(x) for (int j = 0; j < x; ++j)

typedef long long ll;

const int INF = 2e9 + 5;
const int alength=100100;

int main() {
	int x,y,a,b,c;
	cin>>x>>y>>a>>b>>c;
	int p[alength]={},q[alength]={},r[alength*3]={};
	fori(a){cin>>p[i];}
	fori(b){cin>>q[i];}
	fori(c){cin>>r[i];}
	sort(p,p+a,greater<int>());sort(q,q+b,greater<int>());
	fori(x){
		r[c+i]=p[i];
	}
	fori(y){
		r[c+x+i]=q[i];
	}
	sort(r,r+c+x+y,greater<int>());
	ll ans=0;
	fori(x+y){
		ans+=r[i];
	}
	cout<<ans;
}