#include<bits/stdc++.h>
#define ll long long
using namespace std;
pair<int,int> a[100050];
void solve(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].first);
		a[i].second=i;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		printf("%d ",a[i].second);
	}
	
}

signed main(){
    int t=1;
    //scanf("%d",&t);
    for(int i=1;i<=t;i++){
        solve();
    }
    return 0;
}