#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<int,int> P;
#define M 1000000007
#define F first
#define S second
#define PB push_back
#define INF 100000000000000000
int n,a=-1,b=-1,c=-1,as=0,bs=0,cs=0;
int main(void){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(a==-1)a=x;
		if(a!=x&&b==-1)b=x;
		if(a!=x&&b!=x&&c==-1)c=x;
		if(a!=x&&b!=x&&c!=x){
			printf("No\n");
			return 0;
		}
		if(a==x)as++;
		if(b==x)bs++;
		if(c==x)cs++;
	}
	if(n%3!=0&&as==n&&a==0)printf("Yes\n");
	else if(n%3==0&&a!=-1&&b!=-1&&c!=-1&&as==n/3&&bs==n/3&&cs==n/3&&((a^b)==c))printf("Yes\n");
	else if(n%3==0&&a!=-1&&b!=-1&&c==-1&&((as==n/3&&a==0)||(bs==n/3&&b==0)))printf("Yes\n");
	else if(n%3==0&&a!=-1&&b==-1&&c==-1&&a==0)printf("Yes\n");
	else printf("No\n");
}
