#include <string.h>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <istream>
#define INF 2147483647
#define LLINF 9223372036854775807
typedef long long ll;
using namespace std;
pair<ll,ll> a[55];
bool vis[55];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
	}
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	sort(a,a+n);
	int ans=1000000000;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			int cnt=0;
			ll p=a[j].first-a[i].first;
			ll q=a[j].second-a[i].second;
			memset(vis,0,sizeof(vis));
			for(int l=0;l<n;l++){
				if(!vis[l])cnt++;
				else continue;
				int laf=a[l].first;
				int lar=a[l].second;
				for(int o=l+1;o<n;o++){
					if(a[o].first-laf==p&&a[o].second-lar==q){
						vis[o]=1;
						laf=a[o].first;
						lar=a[o].second;
					}
				}
			}
			ans=min(ans,cnt);
		}
	}
	cout<<ans<<endl;
	return 0;
}