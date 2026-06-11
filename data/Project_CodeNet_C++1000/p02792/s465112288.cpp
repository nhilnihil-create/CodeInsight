#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
using P = pair<int,int>;

int main(){
	int N;
	cin >> N;
	string S=to_string(N);
	int siz=S.size(), ans=0;
	int M=S[0]-'0', m=S[S.size()-1]-'0';
	for(int i=1; i<=N; i++){
		string a=to_string(i);
		int as=a[0]-'0', ae=a[a.size()-1]-'0';
		if(ae==0) continue;
		if(as==ae) ans++;
		if(ae==M){
			rep(j,siz-2) ans+=pow(10,j);
			int res=N-M*pow(10,siz-1);
			res/=10;
			ans+=res;
			if(as<=m) ans++;
		}
		else if(ae<M){
			rep(j,siz-1) ans+=pow(10,j);
		}
		else{
			rep(j,siz-2) ans+=pow(10,j);
		}
	}
	if(siz==1) ans--;
	cout << ans << endl;

	return 0;
}