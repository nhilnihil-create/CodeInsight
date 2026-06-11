#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
  	cin>>s;
  
  	long long int L=s.size();
  	long long int n=0;
  	long long int p=1;
  	int d[2019]={0};
  	long long int cnt=0;
  	d[0]++;
    for(int i=L-1;i>=0;i--){
        n=(n+(s[i]-'0')*p)%2019;
      	p=(p*10)%2019;
        d[n]++;
    }
  	for(int i=0;i<2019;i++){
    	cnt+=d[i]*(d[i]-1)/2;
    }
	
  	cout<<cnt<<endl;
}
