#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+233;

int a[maxn];
int main() {
	int k;
	cin>>k;
	int flag=0;
	a[1] = 7%k;
	for(int i=2;i<= k;i++) {
		a[i]=(a[i-1]*10+7)%k;
	}
	for(int i=1;i<=k;i++){
		if(a[i]==0){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	
	return 0;
}