#include<bits/stdc++.h>
#include <algorithm>
using namespace std;


int main(){
	int h,k,d;
	cin>>h>>k;
	int a[h];
	long long c=0;
	for(int i =0 ; i<h ; i++){
		cin>>d;
		a[i]=d;
		}
    sort(a,a+h);
    for(int j=0;j<h-k;j++){
    	c+=a[j];
	}
	if(k>=h){
		cout<<"0";
	}
	else
	cout<<c;
return 0 ;
}
