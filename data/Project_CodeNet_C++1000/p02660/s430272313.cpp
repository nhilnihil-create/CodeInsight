#include<iostream>
#include<math.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define lrep(i,n) for(long int i=0;i<(n);i++)
using namespace std;
int main(){
	long int n;
	cin >> n;
	long N=n;
	long count=0,counta;
	for(int a=2;a<=sqrt(N);a++){
		counta=0;
		while(!(n%a)){
			n=n/a;
			counta++;
		}
		for(int k=1;k<=counta;k++){
			counta-=k;
			count++;
		}
	}
	if(n!=1) count++;
	cout << count;
}