#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1010, M = 64;
ll a[N];int n;char s[N];ll b[N];
 
ll insert(ll x){
	for(int i=60;~i;i--)if(1&(x>>i)){
		if(!b[i]){b[i]=x;break;}
		else x^=b[i];
	}
	return x;
}
 
void Main()
{
	for(int i=0;i<M;i++)b[i]=0;
	cin >> n;for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	scanf("%s",s+1);
	bool Ans=0;
	for(int i=n;i;i--){
		if(s[i]=='0'){
			insert(a[i]);
		}else{
			ll d=insert(a[i]);
			// cerr << d << "??" << endl;
			Ans|=d!=0;
		}
	}
	printf("%d\n",(int)Ans);
}

int main(){int T;cin >>  T;while(T--)Main();}