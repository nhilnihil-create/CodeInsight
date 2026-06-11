#include<bits/stdc++.h>
using namespace std;
const int MAXN = 7+1e5;
typedef long long LL;
int n,m;
int Lmin[MAXN],Rmin[MAXN];
int a[MAXN];
 
void Read()
{
    //#define TASK "ABC"
    //freopen(TASK ".inp", "r", stdin); freopen(TASK ".out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i=1 ; i<=n ; ++i) cin >>a[i];
}
void Magic(){
	
	a[n+1] = MAXN;
	Lmin[0] = 0;
    Rmin[n] = n+1;
 
    for (int i=1; i<=n; ++i)
        if ( a[i] < a[i-1] ) Lmin[i] = i-1;
        else {
            int x = Lmin[i-1];
            while( a[x] < a[i] && x)
                x = Lmin[x];
            Lmin[i] = x;
        }
 
    for (int i=n-1; i; --i)
        if ( a[i] < a[i+1] ) Rmin[i] = i+1;
        else {
            int x = Rmin[i+1];
            while( a[x] < a[i] && x <= n)
                x = Rmin[x];
            Rmin[i] = x;
        }
}

void Solve(){
	
	LL ans = 0;
    for (int i=1; i<=n; ++i) {
        int cnt = 0,
            l = Lmin[i],
            r = Rmin[i];
        if ( l>0 ) {
            --l;
            while( a[l] < a[i] && l ) l = Lmin[l];
            cnt += (Rmin[i] - i )* (Lmin[i] - l);
        }
        if ( r<n+1 ) {
            ++r;
            while( a[r] < a[i] && r<=n) r = Rmin[r];
            cnt += (r - Rmin[i] )* (i - Lmin[i]) ;
        }
        ans += LL(cnt)*a[i];
    }
    
    cout <<ans;
}

int main(){
	
	Read();
	Magic();
	Solve();
	return 0;
	
}
 
    
