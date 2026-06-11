#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;

int main() {
    int n,l;cin>>n>>l;
    int a[n];
    int m = 1000;
    int sum = 0;
    rep(i,n){
        a[i] = l + i;
        sum += a[i];
        if(abs(a[i])<abs(m))m=a[i];
    }
    
    int ans = sum - m;
    cout<<ans<<endl;
	return 0;
}