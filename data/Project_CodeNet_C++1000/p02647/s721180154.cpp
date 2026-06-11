#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INTINF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	int tmp;
    int n, k;
    cin >> n >> k;
    int a[n], d[n+1]={};
    REP(i,n) cin >> a[i];
    REP(i,k){
    	REP(j,n+1) d[j]=0;
    	REP(j, n){
    		d[max(0,j-a[j])]++;
    		d[min(n-1, j+a[j])+1]--;
      	}
        bool ch = true;
    	REP(j, n){
    		if(j==0) a[j] = d[j];
    		else a[j] = a[j-1] + d[j];
    		if(a[j] < n) ch = false;
    	}
    	if(ch) break;
    }
    REP(i,n) cout << a[i] << " ";
    cout << endl;
}
