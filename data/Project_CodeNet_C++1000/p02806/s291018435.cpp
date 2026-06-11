#include <cstdio>
#include <string>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
inline int rd(){
    int x=0,p=1;
    char a=getchar();
    while((a<48||a>57)&&a!='-')a=getchar();
    if(a=='-')p=-p,a=getchar();
    while(a>47&&a<58)x=(x<<1)+(x<<3)+(a&15),a=getchar();
    return x*p;
}
const int N=1002;
int n,a[N];
string s[N],str;
ll ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i]>>a[i];
	cin>>str;
	for(int i=1,flag=0;i<=n;i++){
		ans+=flag*a[i];
		if(str==s[i])flag=1;
	}
	printf("%lld\n",ans);
    return 0;
}