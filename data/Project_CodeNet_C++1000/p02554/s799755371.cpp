#include <iostream>
using namespace std;
int main() {
    long long n,a=10,b=9,c=8,mod=1000000007;
	cin>>n;
    for(int i=1;i<n;i++) {
        a=a*10%mod;
        b=b*9%mod;
        c=c*8%mod;
    }
    a=(a+c)%mod;
  	cout<<(a-(2*b)%mod+mod)%mod<<endl;
  	return 0;
}