#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#define ll long long
#define maxn 500005 
using namespace std;
char a[maxn];
int len,ans[maxn],cnt;
struct ru{
	int now,zhi,mo;
} p[maxn];
int cmp(ru s1, ru s2){
    return s1.zhi>s2.zhi;
}
int main(){
	a[0]=1;
	cin>>a+1;len=strlen(a)-1;
	int sum=0,nows=0,moo=0;
	for(int i=1;i<=len;i++){
		if (a[i]!=a[i-1]){
			p[cnt].now=nows;
			p[cnt].zhi=sum;
			p[cnt].mo=moo;
			cnt++;
			sum=1;nows=i;
			if(a[i]=='<') moo=1;
			else moo=2;
		} else sum++;
	}
		p[cnt].now=nows;
		p[cnt].zhi=sum;
		p[cnt].mo=moo;
		sort(p+1,p+cnt+1,cmp);
		memset(ans,-1,sizeof(ans));
		for(int i=1;i<=cnt;i++){
			int now1=0;
			if(p[i].mo==1)
			for(int j=p[i].now;j<=p[i].now+p[i].zhi;j++){
				if(ans[j]==-1) ans[j]=now1;
				now1++;
				
			} else{
				for(int j=p[i].now+p[i].zhi;j>=p[i].now;j--){
				if(ans[j]==-1) ans[j]=now1;
				now1++;
				}
			}
		}
		ll anss=0;
//		for(int i=1;i<=len+1;i++) cout<<ans[i]<<" ";cout<<endl;
		for(int i=1;i<=len+1;i++) anss+=(ll)ans[i];
		cout<<anss;
}