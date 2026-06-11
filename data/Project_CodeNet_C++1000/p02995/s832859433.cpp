#include <iostream>
#include <numeric>
using namespace std;

long long gcd(long long a,long long b){
	long long tmp;
	if(a > b){
		while(b != 0){
			tmp = b;
			b = a%b;
			a = tmp;
		}
		return a;
	}else{
		while(a != 0){
			tmp = a;
			a = b%a;
			b = tmp;
		}
		return b;
	}
}

long long lcm(long long a,long long b){
	long long max_common = gcd(a,b);
	return (a/max_common)*b;
}

int main(){
    long long a, b, c, d, cnt=0;
    cin >> a >> b >> c >> d;
    long long x = lcm(c,d);
    long long ans = (b-a+1) - ( (b/c - (a-1)/c) + ((b/d) - (a-1)/d) - (b/x-(a-1)/x) );
    cout << ans << endl;
    return 0;
}
