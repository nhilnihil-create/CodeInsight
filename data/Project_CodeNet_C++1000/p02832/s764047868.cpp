//Author: Fuadul Hasan(fuadul202@gmail.com)
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int N   = 2e5 + 5;

int main(){
	
	int n;
	cin>>n;

	int a[n];

	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int cnt  = 1;
	for(int i=0;i<n;i++){
		if(a[i] == cnt){
			cnt++;
		}
	}

	//printf("%d\n", cnt);
	if(cnt == 1){
		cout<<-1<<endl;
	}
	else{
		cout<<n - (cnt-1)<<endl;
	}
	

	return 0;
}