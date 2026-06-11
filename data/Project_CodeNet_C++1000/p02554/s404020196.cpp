#include<cstdio>
//#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const int maxv = 10005;
const int inf = 1e9 + 7;
ll fpow(int x,int y){
	ll res=1;
    for(ll i=0;i<y;i++){
        res=res*x%inf;
    }
    return res;
}
int main(){
	int n;
	scanf("%d",&n);
	ll ans=fpow(10,n)-2*fpow(9,n)+fpow(8,n);
	ans%=inf;
	if(ans<0) ans+=inf;
	printf("%lld\n",ans);
	return 0;
}
