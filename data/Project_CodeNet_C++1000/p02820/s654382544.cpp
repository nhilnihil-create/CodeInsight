#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const char nl = '\n';

// INT VS LL

int win(char c){
	if (c=='r') return 2;
	if (c=='p') return 1;
	return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;
    int a[3], ans=0;
    cin>>a[0]>>a[1]>>a[2];
    string t;
    cin>>t;
    vector<int> w(n);
    for (int i=0; i<n; ++i){
    	// cout<<win(t[i])<<nl;
    	int cur=win(t[i]);
    	if (i-k<0){
    		ans+=a[cur];
    		w[i]=cur;
    	}
    	else{
    		if (cur!=w[i-k]){
    			ans+=a[cur];
    			w[i]=cur;
    		}
    		else w[i]=-1;
    	}
    }
    cout<<ans<<nl;

    return 0;
}