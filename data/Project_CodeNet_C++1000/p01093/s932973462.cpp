#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,temp;
	while(1){
		cin >> n;
		if(n==0) break;
		int a[n],sa[n-1],min=1000000;
		for(int i=0;i<n;i++){
			cin >> a[i];
		}
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(a[i]>a[j]){
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
		for(int i=1;i<n;i++){
			if(a[i]>a[i-1]){
				sa[i]=a[i]-a[i-1];
			}else{
				sa[i]=a[i-1]-a[i];
			}
			if(min>sa[i]){
				min=sa[i];
			}
		}
		cout << min << endl;
	}
}
		
