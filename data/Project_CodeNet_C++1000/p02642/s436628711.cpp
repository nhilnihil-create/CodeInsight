#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 1e6 + 2;
int dv[N];
signed main(){
    int t = 1; //cin >> t;
    while(t--){
    	int n; cin >> n;
    	vector<int> a(n);
    	for(int i = 0; i < n; i++) 
    		cin >> a[i];
    	int mx = *max_element(a.begin(),a.end());
    	for(int i = 0; i < n; i++)
    	{
    		for(int j = a[i]; j <= mx; j += a[i])
    			dv[j]++;
    	}
    	int ans = 0;
    	for(int i = 0; i < n; i++)
    		if(dv[a[i]] == 1)
    			ans++;
    	cout << ans;
    }    
}