#include <bits/stdc++.h>
using namespace std;

int main(){
	long n;
	string sign;
	getline(cin, sign,'\n');
	n = sign.length();
	
	long data[n+1];
	
	for(long i=0;i<=n;i++){
		data[i]=0;
	}
	
	long val = 1;
	for(long i=0;i<n;i++){
		if(sign[i]=='<'){
			data[i+1] = val;
			val++;
		}else{
			data[i+1] = 0;
			val = 1;
		}
	}
	val = 1;
	for(long i=n-1;i>=0;i--){
		if(sign[i]=='>'){
			data[i] = (data[i]<val)?val:data[i];
			val++;
		}else{
			val = 1;
		}
	}
	long sum = 0;
	for(long i=0;i<=n;i++){
		sum+=data[i];
	}
	cout << sum << "\n";
}
