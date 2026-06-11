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

struct info{
	int x;
	bool y;
};

int counter(int x){
	if(x==0)return 0;
	return counter(x>>1)+(x&1);
}

int main() {
	int n;
	cin>>n;
	info inf[20][20];
	int a[20];
	for(int i=1;i<=n;++i){
		cin>>a[i];
		for(int j=1;j<=a[i];++j){
			int hoge;
			cin>>inf[i][j].x>>hoge;
			inf[i][j].y=hoge==1;
		}
	}
	int ans=0;
	for(int bit=1;bit<(1<<n);++bit){
		bool f=true;
		for(int i=1;i<=n;++i){
			if(!(bit&(1<<i-1)))continue;//不親切なのでこの人の証言の真偽を確かめる必要がない
			for(int j=1;j<=a[i];++j){
				if(((bit>>(inf[i][j].x-1))&1)^inf[i][j].y)f=false;
			}
		}
		if(f)ans=max(ans,counter(bit));
	}
	cout<<ans;
}