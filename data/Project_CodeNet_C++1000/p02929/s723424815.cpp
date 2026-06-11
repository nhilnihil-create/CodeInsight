#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;
string s;
int cnt[2];

int main(void){
	scanf("%d",&n);
	cin >> s;
	for(int i=0;i<n*2;i++){
		if(s[i]=='B'){
			cnt[1]++;
		}else{
			cnt[0]++;
		}
	}
	if(s[0]=='W' || s[n*2-1]=='W'){
		printf("0\n");
		return 0;
	}
	bool flag=false;
	ll ans=1;
	ll cnt=1;
	for(int i=1;i<n*2;i++){
		if(s[i]==s[i-1]){
			flag=!flag;
		}
		if(!flag){
			cnt++;
		}else{
			ans=ans*cnt%MOD;
			cnt--;
		}
	}
	if(cnt!=0){
		printf("0\n");
		return 0;
	}
	for(ll i=1;i<=n;i++){
		ans=ans*i%MOD;
	}
	printf("%lld\n",ans);
	return 0;
}
