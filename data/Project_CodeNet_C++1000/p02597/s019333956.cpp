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

int N;
char s[maxn];
void solve(){
	int ans =0;
	int l = 1,r = N;
	while(l<r){
		while(l<=N && s[l] == 'R') l++;
		while(r>=1 && s[r] == 'W') r--;
		if(l<r) ans++;
		l++,r--;
	}
	cout<<ans<<'\n';
}
int main(){
	// debug;
	ios;

	cin>>N;
	cin>>(s+1);
	solve();
	
	return 0;
}
