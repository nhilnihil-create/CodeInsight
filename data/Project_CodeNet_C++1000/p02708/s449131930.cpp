#include <iostream>
using namespace std;
#define NUM 1000000007

int main(){
	int n, k;
  	cin>>n>>k;
	
  	long long int cnt=0;
  	long long int sum=0;
  	for(long long int i=k;i<=n+1;i++){
    	long long int n1=i*(i-1)/2, n2=i*(2*n-(i-1))/2;
      	cnt+=(n2-n1)+1;
      	if(cnt>NUM){
        	sum+=cnt%NUM;
          	cnt=0;
        }
    }
  	sum+=cnt;
  	
  	cout<<sum%NUM<<endl;
  	return 0;
}
