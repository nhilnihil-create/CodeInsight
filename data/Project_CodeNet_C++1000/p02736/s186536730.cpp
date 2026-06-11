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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll a[n];
    bool niko=false;
    for(int i=0;i<n;i++){
    	a[i]=(s[i]-'1');
    	if(a[i]==1)niko=true;
    }
    n--;
    bool maki=false;
    for(int i=0;i<=n;i++)maki^=(a[i]&1)&(i==(n&i));
    if(maki){
    	cout << 1<<endl;
    	return 0;
    }
    if(niko){
    	cout << 0 <<endl;
    	return 0;
    }
    for(int i=0;i<=n;i++)a[i]/=2;
    maki=false;
    for(int i=0;i<=n;i++)maki^=(a[i]&1)&(i==(n&i));
    cout << ((maki)?2:0) <<endl;
    return 0;
}
