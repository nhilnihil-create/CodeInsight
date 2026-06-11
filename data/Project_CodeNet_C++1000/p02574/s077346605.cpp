#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int c[N],a[N];

int gcd(int n,int m){
	if(m==0)return n;
	return gcd(m,n%m);
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		c[a[i]]++;
	} 
	int _gcd=0,f=0;
	for(int i=0;i<n;i++){
		_gcd=gcd(_gcd,a[i]);
	}
	//printf(">\n");
	for(int i=2;i<N;i++){
		int cnt=0;
		for(int j=i;j<N;j+=i){
		//	printf("%d %d\n",i,j);
			cnt+=c[j]; 
			if(cnt>1){
				f=1;break;
			}
		}
		if(f)break;
	}
	if(f==0&&_gcd==1){
		printf("pairwise coprime\n");
	}else if(_gcd==1&&f)printf("setwise coprime\n");
	else printf("not coprime\n");
}

/*
1、任意两个互素
2、总gcd==1 且存在不互素的
3、其他 

*/ 