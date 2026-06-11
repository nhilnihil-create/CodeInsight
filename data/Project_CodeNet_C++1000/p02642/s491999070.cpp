#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define init(a,i) for(int k=0;k<(i);k++)(a)[k]=0;
#define in(a,i) for(int k=0;k<(i);k++)cin>>(a)[k];
int main(){
	bool num[1000001];
	init(num,1000001);
	int n;
	cin>>n;
	int a[n+1];
	in(a,n);
	a[n]=1000001;
	sort(a,a+n+1);
	int count=0;
	for(int i=0;i<n;i++){
		if(num[a[i]]==0){
			if(a[i]!=a[i+1])count++;
			for(int j=1;a[i]<=1000000/j;j++)num[a[i]*j]=1;
		}
	}
	cout << count;
}
