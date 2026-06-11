#include<bits/stdc++.h>
#define fo(i,a,b) for((i)=(a);i<=(b);i++)
#define rfo(i,a,b) for((i)=(a);i>=(b);i--)
#define inrange(x,y,z) (((x)>=(y))&&((x)<=(z)))
#define ALL(vec) ((vec).begin(),(vec).end())
#define SOR(vec) sort(ALL(vec))
#define UNI(vec) (vec).erase(unique(ALL(vec)),(vec).end())
using namespace std;
typedef unsigned long long ull;
int n;
ull a[100100],x,bl;
ull umi(ull a,ull b){
	return (a<b)?a:b;
}
ull uma(ull a,ull b){
	return (a>b)?a:b;
}
int main(){
	#ifdef FILIN
		#ifndef LOCAL
			freopen(FILIN,"r",stdin);
			freopen(FILOUT,"w",stdout);
		#endif
	#endif
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		x^=a[i];
	}
	for(int i=0;i<n;i++)
		a[i]&=(~x);
	int rk=0,pos;
	for(int i=59;i>=0;i--){
		pos=-1;
		for(int j=rk;j<n;j++){if((a[j]>>i)&1){pos=j;break;}}
		if(pos==-1) continue;
		if(pos>rk) a[rk]^=a[pos];
		for(int j=rk+1;j<n;j++)
			a[j]=umi(a[j],a[j]^a[rk]);
		rk++;
	}
	for(int i=0;i<n;i++)
		bl=uma(bl,bl^a[i]);
	cout<<bl*2+x<<endl;
	return 0;
}
