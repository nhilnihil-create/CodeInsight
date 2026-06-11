#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int a,b,k;
	cin>>a>>b>>k;
	if(a==k){
		cout<<"0 "<<b;
	}
	else{
		if(a<k){
			cout<<"0 "<<max((b-k+a),0ll);
		}
		else{
			cout<<(a-k)<<" "<<b;
		}
	}
	return 0;
}