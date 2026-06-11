#include<bits/stdc++.h>
#define fi first
#define se second
#define lson l,mid,p<<1
#define rson mid+1,r,p<<1|1
#define pb push_back
#define ll long long
using namespace std;
const int inf=1e9;
const int mod=1e9+7;
const int maxn=1e5+10;
int main(){
	//ios::sync_with_stdio(false);
		//freopen("in","r",stdin);
	int n;
	cin>>n;
	if(n&1){
		cout<<n/2<<endl;
	}else cout<<n/2-1<<endl;
	return 0;
}