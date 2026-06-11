#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define debug  freopen("in.txt","r",stdin),freopen("out.txt","w",stdout);
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 1e6+10;
const int maxM = 1e6+10;
const int inf = 0x3f3f3f3f;

int N,M;
int main(){
	// debug;
	ios;

	cin>>N>>M;
	if(N&1){
		for(int i = 1;i<=M;i++){
			cout<<i<<" "<<N-i+1<<'\n';
		}
	}else{
		int mid = N/2;
		for(int i = 1;i<=min(M,mid/2);i++){
			cout<<i<<" "<<mid-i+1<<'\n';
		}
		M -= min(M,mid/2);
		for(int i = 1;i<=M;i++){
			cout<<i+mid<<" "<<N-i<<'\n';
		}
	}

	return 0;
}
