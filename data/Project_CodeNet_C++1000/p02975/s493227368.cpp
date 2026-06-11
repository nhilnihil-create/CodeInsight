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
	int n;map<ll,int> m;vector<ll> a;
	cin>>n;
	fori(n){
		int hoge;
		cin>>hoge;
		auto itr=m.find(hoge);
		if(itr!=m.end()){
			++m[hoge];
		}else{
			m[hoge]=1;
			a.push_back(hoge);
		}
	}

	sort(a.begin(),a.end());

	if(m.size()==1&&a[0]==0){
		cout<<"Yes";return 0;
	}
	if(m.size()==2&&a[0]==0&&m[0]==n/3){
		cout<<"Yes";return 0;
	}
	if(n%3==0&&m.size()==3&&(m[a[0]]==n/3)&&(m[a[1]]==n/3)&&(m[a[2]]==n/3)&&(a[0]^a[1]^a[2])==0){
		cout<<"Yes";return 0;
	}
	cout<<"No";
}