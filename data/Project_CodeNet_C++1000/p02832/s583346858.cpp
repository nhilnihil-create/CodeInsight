#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

#define MAXX 500005
#define INF INT_MAX

#define PI   3.14159265358979323846264338327950

#define PB push_back
#define PF push_front
#define F first
#define S second

#define fixx(n) fixed << setprecision(n)

#define ll 	 long long

#define mod  1000000007



int main()
{
	FAST;
	int cnt[MAXX] = {0};
	int n;
	cin >> n;
	int a[n+6];
	bool fl = false;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		if(a[i] == 1){
			fl = true;
		}
	}
	if(!fl){
		cout << -1;
		return 0;
	}
	int h = 1;
	for(int i = 0; i < n; i ++){
		if(a[i] == h){
			h ++;
		}
	}
	cout << n - h + 1;
	return 0;
}