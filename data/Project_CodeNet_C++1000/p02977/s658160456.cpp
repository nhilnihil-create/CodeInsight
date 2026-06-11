#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=100005;
int n;
void print(int u,int v){printf("%d %d\n",u,v);}

int main(){
	scanf("%d",&n);
	int t=1;
	while(t<n)t<<=1;
	if(t==n){
		puts("No");
		return 0;
	}
	puts("Yes");
	print(1,2);
	print(2,3);
	print(3,1+n);
	print(1+n,2+n);
	print(2+n,3+n);
	for(int i=4;i<n;i+=2){
		print(i,i+1);
		print(i+1,1);
		print(1,i+n);
		print(i+n,i+1+n);
	}
	if(n%2==0){
		print(n-1,n);
		print((n^(n-1))-1+n,n+n);
	}
	return 0;
} 