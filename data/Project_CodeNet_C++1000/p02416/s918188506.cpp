#include <bits/stdc++.h>
#define endre getchar();getchar();return 0
#define INF 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
#define P pair<int,int>
#define prique(T) priority_queue<T,vector<T>,greater<T>>
#define vecunique(vec) sort(vec.begin(), vec.end());decltype(vec)::iterator result = std::unique(vec.begin(), vec.end());vec.erase(result, vec.end())
using namespace std;
signed main(){
	string n;
	while(true){
		cin>>n;
		if(n=="0")break;
		int ans=0;
		for(int i=0;i<n.size();i++){
			ans+=n[i]-'0';
		}
		cout<<ans<<endl;
	}
	return 0;
}
