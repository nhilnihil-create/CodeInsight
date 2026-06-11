#include <bits/stdc++.h>
 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int n,k;
	cin>>n>>k;
	if(n<k){
		cout<<min(n,(abs(n-k)));
	}
	else if(n==k){
		cout<<"0";
	}
	else{
		if(n%k==0){
			cout<<"0";
		}
		else{
			cout<<min((n%k),abs((n%k)-k));
		}
	}
	return 0;
}