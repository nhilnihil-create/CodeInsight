#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;

const int maxn = 200090;

int a,b,ans;

ll read(){ ll s=0,f=1; char ch=getchar(); while(ch<'0' || ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } while(ch>='0' && ch<='9'){ s=s*10+ch-'0'; ch=getchar(); } return s*f; }

int main(){
	ans=0;
	a = read(),b = read();
	int t = 1;
	while(t<b){
		++ans;
		t=t+a-1;
	}
	printf("%d\n",ans);
	
	return 0;
}