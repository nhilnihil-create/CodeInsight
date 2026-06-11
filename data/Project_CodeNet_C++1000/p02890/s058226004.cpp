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
    int n,a;
    cin>>n;
    int b[n+1];
    memset(b,0,sizeof(b));
    vector<int> v1,v2;
    v1.pb(0);
    for(int i=0;i<n;i++){
    	cin>>a;
    	b[a]++;
    }
    for(int i=0;i<=n;i++){
    	if(b[i])v1.pb(b[i]);
    }
    sort(be(v1));
    v2=v1;
    int niko=v1.size();
    for(int i=1;i<niko;i++){
    	v2[i]+=v2[i-1];
    }
    for(int k=1;k<=n;k++){
    	int le=0,ri=n/k+1,ans;
    	while(ri-le>1){
    		ans=(le+ri)/2;
    		int idx=(lower_bound(be(v1),ans)-v1.begin());
    		if((v2[idx-1]+(niko-idx)*ans)>=ans*k)le=ans;
    		else ri=ans;
    	}
    	cout << le <<endl;
    }

    return 0;
}
