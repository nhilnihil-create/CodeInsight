#include<bits/stdc++.h>
 
using namespace std;

#define debug(x) cout << (#x) << " is " << x << endl;
#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;

#define N 200005
lli a[N];
lli n, k;

bool ck(lli l){
	lli cnt = 0;
	for(lli i=0; i<n; i++){
		if(a[i]%l == 0) cnt += (a[i]/l)-1;
		else cnt += a[i]/l;
	}
	return cnt <= k;
}

int main()
{
    cin >> n >> k;
    lli mx = 0;
    for(lli i=0; i<n; i++){
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	lli lo=1, hi=mx, mid, ans=mx;
	while(lo <= hi){
		mid = lo + (hi-lo)/2;
		if(ck(mid)){
			ans = mid;
			hi = mid-1;
		}
		else lo = mid+1;
	}
	cout << ans << endl;
     
    return 0;
}
