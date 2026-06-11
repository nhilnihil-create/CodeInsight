#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,w[N]; char s[N];
inline int read(){
	int num=0; char g=getchar(); while(g<48||57<g) g=getchar();
	while(47<g&&g<58) num=(num*10)+g-48,g=getchar(); return num;
}
inline int getans(int a,int b){
	int ans=1;
	while(a>0&&b>0) {if(a%2<b%2) ans=0; a/=2,b/=2;} return ans;
}
int main(){
	n=read(); bool fl=0; int sum=0; scanf("%s",s+1);
	for(int i=1;i<=n;i++) w[i]=s[i]-'1';
	for(int i=1;i<=n;i++) if(w[i]==1) fl=1;
	for(int i=1;i<=n;i++) if(fl==1&&w[i]==2) w[i]=0;
	for(int i=1;i<=n;i++) if(getans(n-1,i-1)) sum^=w[i];
	cout<<sum<<endl;
	return 0;
}