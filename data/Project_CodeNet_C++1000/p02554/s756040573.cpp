#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const long long INF=1e9+7;
long long pow(long long a,long long b){
	long long res=1;
	while(b){
		if(b&1) {
			res=res*a%INF;
		}
		a=a*a%INF;
		b>>=1;
	}
	return res;
}
int main(int argc, char** argv) {
	long long n;
	cin>>n;
	cout<<((pow(10ll,n)-2*pow(9ll,n)+pow(8ll,n))%INF+INF)%INF;
	return 0;
}