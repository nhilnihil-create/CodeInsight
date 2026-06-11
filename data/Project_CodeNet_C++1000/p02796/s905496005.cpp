#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mp make_pair
#define f first
#define s second

//var 
int n,x,L,l,r, ans,i,j, rm = INT_MIN;
pii rng[100001];

int main(){
	cin >> n;
	for(int i = 1; i<=n; i++){
		cin >> x >> L;
		l = (x-L);
		r = (x+L);
		rng[i] = mp(r,l);
	}
	ans = 0; 
	sort(rng+1,rng+n+1);
	i = 1;
	for(int i = 1; i<=n; i++){ 
		//cout << rng[i].s << " " << rng[i].f << endl;
		if(rng[i].s >= rm){
			ans++;
			rm = rng[i].f;
		}
	}
	cout << ans << endl;
}