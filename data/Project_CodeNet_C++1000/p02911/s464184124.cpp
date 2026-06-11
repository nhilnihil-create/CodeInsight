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
	ll n,k,q;
	cin>>n>>k>>q;
	int m[alength]={};
	fori(q){
		int hoge;cin>>hoge;
		++m[hoge-1];
	}
	fori(n){
		if(m[i]-q+k>0){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
	}
}