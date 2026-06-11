#include <bits/stdc++.h>
using namespace std;

int n,t,tarr[51],total,totalnot;
string s,x,arr[51];

int main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>s>>t;
		arr[i] = s;
		tarr[i] = t;
		total = total + t;
	}
	cin>>x;
	for(int i = 1;i <= n;i++){
		if(arr[i] != x){
			totalnot = totalnot + tarr[i];
		}else{
			totalnot = totalnot + tarr[i];
			break;
		}
	}
	cout<<total - totalnot<<endl;
}
