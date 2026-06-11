#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
typedef pair<int,int> pa;
typedef vector<int> vec;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
int n,h[500010];
int lowbit(int x){
	return x&-x;
}
int main(){
	cin>>n;
	if  (lowbit(n)==n) return puts("No"),0;
	puts("Yes");
	printf("1 2\n");
	printf("2 3\n");
	printf("3 %d\n",n+1);
	printf("%d %d\n",n+1,n+2);
	printf("%d %d\n",n+2,n+3);
	h[2]=2;
	h[3]=3;
	for (int i=4;i<n;i+=2){
		printf("%d %d\n",i,i+1);
		printf("%d %d\n",i+1,1);
		printf("%d %d\n",n+1,n+i);
		printf("%d %d\n",n+i,n+i+1);
		h[i]=n+i;
		h[i+1]=i+1;
	}
	if (n%2==0){
		printf("%d %d\n",n,h[n-lowbit(n)]);
		printf("%d %d\n",n+n,h[lowbit(n)^1]);
	}
	return 0;
}