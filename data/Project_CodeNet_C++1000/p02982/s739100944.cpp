#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl





using ll = long long;

const ll mod = 1e9+7;
const int maxn = 30;



int n, d;
int x[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);

    cin>>n>>d;
    int res=0;
    for (int i=0; i<n; i++) {
	for (int j=0; j<d; j++) {
	    cin>>x[i][j];
	}
    }
    for (int i=0; i<n; i++) {
	for (int j=i+1; j<n; j++) {
	    ll dist=0;
	    for (int k=0; k<d; k++) {
		dist += 1ll*(x[i][k]-x[j][k])*(x[i][k]-x[j][k]);
	    }
	    ll f = sqrtl(dist);
	    if (f*f==dist)res++;
	}
    }
    cout<<res<<endl;
    
    
    return 0;
}
