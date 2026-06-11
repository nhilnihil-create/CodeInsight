#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n,m,v,p;
    cin>>n>>m>>v>>p;
    ll a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);reverse(a,a+n);
    ll le=p-1,ri=n;
    while(ri-le>1LL){
    	ll mid=(ri+le)/2;
    	ll num=a[mid]+m;
    	ll sum=0;
    	ll nes=max(0LL,v-(n-mid)-p+1);
    	for(int i=p-1;i<mid;i++)sum+=min(m,max(0LL,num-a[i]));
    	if(nes*m<=sum&&a[p-1]<=num)le=mid;
    	else ri=mid;
    }
    cout << le+1<<endl;
    return 0;
}
