#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e7 + 10;
const ll mod = 1e9 + 7;
int x[maxn],y[maxn];
int main(){
	int n;
	ll ans;
    cin>>n;
    for(int i = 1;i <= n; i++){
        int a,b;
		cin>>a>>b;
        x[i] = a - b;
        y[i] = a + b;
    }
    sort(x + 1,x + n + 1);
    sort(y + 1,y + n + 1);
    ans = max(x[n] - x[1],y[n] - y[1]);
    cout<<ans<<endl;
    return 0;
}