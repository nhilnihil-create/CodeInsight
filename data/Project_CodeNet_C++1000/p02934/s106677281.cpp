#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n; cin>>n;
	double ans=0;
	while(n--){
		int x; cin>>x;
		ans+=1.0/x;
	}
	cout<<pow(ans, -1)<<endl;
}
