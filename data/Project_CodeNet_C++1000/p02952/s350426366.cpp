#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n; cin>>n;
	int ans=0;
	for(int i=1; i<=n; i++){
		int aux = (log10(i)+1);
		if(aux%2!=0)
			ans++;
	}
	cout<<ans<<endl;
}
