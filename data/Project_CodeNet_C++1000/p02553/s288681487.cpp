#include<iostream>
#include<algorithm>
using namespace std;
long long a[2];
long long b[2];
long long c[4];
int main(){
	int i,j,q=1;
	long long maxn;
	cin>>a[1]>>a[2]>>b[1]>>b[2];
	maxn=a[1]*b[1];
	for(i=1;i<=2;i++){
	for(j=1;j<=2;j++){
		if((a[i]*b[j])>maxn){
			maxn=a[i]*b[j];
		}
	c[q]=maxn;
	q++;	
	}
	}
	sort(c+1,c+4);
	cout<<c[4];
	return 0;
}