
#include<stdio.h>
#include<string>
#include <iostream>
#include<string.h>
#include <algorithm>
#include<queue>
using namespace std;


int main(){
	long long n,k;
	cin>>n>>k;
	long t;
	n=n%k;
//	if(n-k>0){
//		t=n-k;
//	}
//	else t=k-n;
//	for(;;){
//		//cout<<t<<"---\n";
//		n= abs(n-k);//1
//		if(n<=t){
//			t=n;
//			int s= abs(n-k);
//			if(s>=t){
//				break;
//			}
//		}
//		
//	}
//if(n<k){
//	n=k%n;
//}
if(k-n<n){
	n=abs(n-k);
}
	cout<<n<<endl;
	return 0;
}