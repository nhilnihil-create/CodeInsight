#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; 
    cin>>n;
	vector<int> ans(n+1,0);
	for(int i=0; i<n-1; i++){
		int x; 
        cin>>x;
		++ans[x];
	}
	for(int i=1; i<=n; ++i){
		cout<<ans[i]<<endl;
	}
	return 0;
}
