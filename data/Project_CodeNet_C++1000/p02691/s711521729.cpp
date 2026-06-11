#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<(n);i++)
#define init(a,i) for(int k=0;k<(i);k++)(a)[k]=0
#define in(a,i) for(int k=0;k<(i);k++)cin>>(a)[k]
#define all(a)  (a).begin(),(a).end()
#define el(a) (a).end()-(a).begin()

int main(){
	int n;
	cin>>n;
	int a[n];
	in(a,n);
	int b[n+1],c[n+1];
	rep(i,n){
		b[i]=a[i]+i+1;
		c[i]=i+1-a[i];
	}
	b[n]=2000000000;
	c[n]=2000000000;
	sort(b,b+n);
	sort(c,c+n);
	int bp=0,cp=0;
	ll sum=0,bcount,ccount;
	while(bp<n&&cp<n){
		if(b[bp]>c[cp])cp++;
		else if(b[bp]<c[cp])bp++;
		else{
			bcount=0;
			for(int start=b[bp];b[bp]==start;bp++)bcount++;
			ccount=0;
			for(int start=c[cp];c[cp]==start;cp++)ccount++;
			sum+=bcount*ccount;
		}
	}
	cout<<sum;
	return 0;
}