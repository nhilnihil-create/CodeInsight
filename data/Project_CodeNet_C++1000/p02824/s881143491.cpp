#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+100;

typedef long long ll;

#define int ll

int n, m, v, p;
int a[N], b[N];

bool check(int sz, int v){
	if(v<=0 || sz == 0)
		return true;
	int all=0;
	for(int i=0 ; i<sz ; i++)
		all += min(b[i], m);
	return all >= v * m;
}

bool can(int ind){
	int cv = v;
	cv -= p-1;
	cv -= n-ind;
	int g = a[ind] + m;
	int sz = 0;
	for(int i=p-1 ; i<ind ; i++){
		if(g < a[i])
			return false;
		b[sz ++] = g - a[i];
	}
	return check(sz, cv);
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> v >> p;
    for(int i=0 ; i<n ; i++)
    	cin >> a[i];
    sort(a, a+n, greater<int>());
    int l=p-1, r=n;
    while(r-l>1){
    	int mid = (l+r)/2;
    	if(can(mid))
    		l = mid;
    	else
    		r = mid;
    }
    cout << l+1 << "\n";
}

























