#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<ll>x(n),y(n);
	
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
	}
	int res = 0, smallest, cur;
    for (int p : {1, -1}) {
        for (int q : {1, -1}) {
            smallest = p * x[0] + q * y[0] + 0;
            for (int i = 1; i < n; ++i) {
                cur = p * x[i] + q * y[i] ;
                res = max(res, cur - smallest);
                smallest = min(smallest, cur);
            }
        }
    }
	cout<<res<<'\n';	
	return 0;
}