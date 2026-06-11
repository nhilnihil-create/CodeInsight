#include<iostream>

#include<sstream>
using namespace std;
bool furui[246912];
int main(){
	int n;
	int j;
	int count;
	stringstream s;
	for(int i=2;i<=246912;i++){
		if(!furui[i]){
			j=i;
			while(j<=246912){
				
				furui[j]=true;
				j+=i;
			}
			furui[i]=false;
		}
	}

	while(cin>>n,n>0){
	count=0;
	for(int i=n+1;i<=n*2;i++)if(!furui[i])count++;
	s << count <<endl;
	}
	cout<<s.str();

	return 0;
}