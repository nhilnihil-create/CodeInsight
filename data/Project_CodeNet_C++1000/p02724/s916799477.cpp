#include<iostream>
using namespace std;
int main(){
	long long int n,hap=0;
	cin>>n;
	while(n>=500){
			n-=500;
			hap+=1000;
		}
    while(n>=5){
    	n-=5;
    	hap+=5;
    }
    cout<<hap;
	return 0;
}