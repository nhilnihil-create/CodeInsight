#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <unordered_map>
typedef long long ll;
using namespace std;
const int mod=1e9+7;
const ll inf=(1e14);

ll solve(){
	int n;
	cin>>n;
	int a[n];
	for(int &i:a) cin>>i;
	//aj+ai = j-i aj-j=-(ai+i)
	//aj+ai = i-j aj+j=-(ai-i)
	int m[n],p[n];
	unordered_map<int,int> mm;
	for(int i=0;i<n;i++){
		m[i]=a[i]-i;
		p[i]=a[i]+i;
		mm[m[i]]++;
	}
	ll ans=0;
	for(int i:p){
		ans+=(mm[-i]);
	}
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t=1;
    //cin>>t;
    while(t--) cout<<solve()<<'\n';
    //while(t--) solve(),cout<<'\n';
    return 0;
}
