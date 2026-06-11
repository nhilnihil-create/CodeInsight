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
	int n;cin>>n;
	ll h[alength]={};fori(n){cin>>h[i];}
	int ans=0,c=0;
	fori(n-1){
		if(h[i]<h[i+1]){
			ans=max(ans,c);
			c=0;
		}else{
			++c;
		}
	}
	ans=max(ans,c);
	cout<<ans;
}