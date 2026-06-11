#include <iostream>
#include <cmath>
using namespace std;
inline void prime_fac(int n){
	int m=(int)floor(sqrt(n)+0.5);
	for (int i=2;i<=m;++i){
		while (n%i==0){
			n/=i;
			cout<<" "<<i;
		}
	}
	if (n!=1){
        cout<<" "<<n;
    }
}
int main(){
	int n;
	cin>>n;
	cout<<n<<":";
	prime_fac(n);
	cout<<endl;
	return 0;
}