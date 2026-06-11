#include <bits/stdc++.h>
using namespace std;
long long n , a , b , beda , maxi , mini;
int main(){
	cin >> n >> a >> b;
	if((abs(a - b) + 1) % 2 == 1){
		beda = abs(a - b)/2;
	}
	else if((abs(a - b) + 1)% 2 == 0){
		if((a - 1) <= (n - b)){
			beda = (a - 1);
			b -= beda;
			if(b % 2 == 1)beda += (b - 1)/2;
			else beda += ((b - 1) / 2) + 1;
		}
		else{
			beda = n - b;
			a += beda;
			if((n - a) % 2 == 0)beda += (n - a)/2;
			else beda += ((n - a)/2) + 1;
		}
	}
	cout << beda << endl;
}