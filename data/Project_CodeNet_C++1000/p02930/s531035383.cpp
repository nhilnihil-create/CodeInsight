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
    int n;
	cin>>n;
	for (int i=0;i<n-1;i++) {
		for (int j=i+1;j<n;j++){
			ll num=i^j;
			ll count=1;
			while(!(num&1))num/=2,count++;
			cout<<count<<" ";
		}
		cout<< endl;
	}
    return 0;
}
