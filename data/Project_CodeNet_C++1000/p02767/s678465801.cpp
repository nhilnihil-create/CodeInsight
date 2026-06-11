#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0);
	int n,mean;
	cin>>n;
	long int stamina1,stamina2,stamina3;
	vector<int> X(n);
	
	for(auto& i:X)
		cin>>i;
	
	mean=0;
	for(auto& i:X)
		mean+=i;
	
	mean/=n;

	stamina2=0;
	stamina1=0;
	stamina3=0;
	for(auto& i:X){
		stamina1+=pow(i-mean,2);
		stamina2+=pow(i-mean-1,2);
	}
	
	stamina3=(stamina1<stamina2?stamina1:stamina2);

	cout<<stamina3;

	return 0;

}