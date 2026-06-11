#include<bits/stdc++.h>
using namespace std;
long long t,a[1000020],k,l;
int main(){
	cin>>t;
	for(long long i=1;i<10;i++){
		a[k++]=i;
	}
	while(1){
		long long x=a[l],o=x%10;
		l++;
		if(o!=0)a[k++]=x*10+o-1;
		a[k++]=x*10+o;
		if(o!=9)a[k++]=x*10+o+1;
		if(k>=t){
			cout<<a[t-1]<<endl;break;
		}
	}
	return 0;
}
/* SO EASY UH */