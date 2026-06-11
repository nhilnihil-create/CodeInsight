#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define dbg(x) cout<< #x << ": " << x << "\n";
using namespace std;
#define inf 1e9+7
#define PI  3.14159265358979323846264338327950L
#define pii pair<ll,ll> 




int  main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a,b,d;
	cin>>a>>b>>d;
	int cnt=0;
	for(int i=a; i<=b; ++i){
		if(i%d==0) cnt++;
	}
	cout<<cnt;
}
    

	


