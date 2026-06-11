#include <bits/stdc++.h>
#define x first
#define y second
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define pbb pair<bool,bool>
#define mp make_pair
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define xmod (ll)(1e9+7) 
#define hmod 1286031825167LL
using namespace std;

int h,w,a,b,s[1005][1005];
int main(){	
    ios::sync_with_stdio(false);
    cin >> h >> w >> a >> b;
    for (int i=1;i<=h;i++){
    	for (int j=1;j<=w;j++){
    		s[i][j]=0;
		}
	}
    for (int i=1;i<=b;i++){
    	for (int j=1;j<=a;j++){
    		s[i][j]=1;
		}
	}
	a=w-a; b=h-b;
	for (int i=h;i>=h-b+1;i--){
		for (int j=w;j>=w-a+1;j--){
			s[i][j]=1;
		}
	}
	for (int i=1;i<=h;i++){
		for (int j=1;j<=w;j++){
			cout << s[i][j];
		}
		cout << "\n";
	}
    return 0;
}	