#include <iostream>
#include<bits/stdc++.h>
using namespace std;
long long int hcf(long long int a,long long int b){
	return b > 0 ? hcf(b, a % b) : a;
}

int main() {
	// your code goes here
	long long int num1,num2,ans=0;
	cin>>num1>>num2;
	long long int hcf12=__gcd(num1,num2);
	set<long long int>s;
	for(long long int i=1;i<=sqrt(hcf12);i++){
		if((hcf12)%i==0){
			long long int a=(hcf12)/i,b=i;
			if(num1%a==0 && num2%a==0){
				s.insert(a);
			}
			if(num1%b==0 && num2%b==0){
				s.insert(b);
			}
		}
	}
	vector<long long int>arr;
	for(auto it=s.begin();it!=s.end();it++){
		arr.push_back(*it);
	}
	for(long long int i=1;i<arr.size();i++){
		if(arr[i]==-1){
			continue;
		}
		ans++;
		for(int j=i+1;j<arr.size();j++){
			if(arr[j]%arr[i]==0){
				arr[j]=-1;
			}
		}
	}
	cout<<ans+1;
	return 0;
}
