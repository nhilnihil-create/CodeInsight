#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
using namespace std;

unsigned long long a[100000+2] = {0};
unsigned long long b[100000+2] = {0};

unsigned long long gcm(unsigned long long _x, unsigned long long _y){
        unsigned long long x, y;
        unsigned long long r=0;
        if( _x<_y ){
                x = _y;
                y = _x;
        }
        else{
                x = _x;
                y = _y;
        }
        r = x % y;
        while(r!=0){
                x = y;
                y = r;
                r = x % y;
        }
        return y;
}

unsigned long long lcm(unsigned long long x, unsigned long long y){
        return (x*y)/gcm(x, y);
}

int main(int argc, char* argv[]){
	int N, M;
	unsigned long long L = 1;
	unsigned long long ans = 0;
	
	cin >> N >> M;
	for(int i=1; i<=N; i++){
		cin >> a[i];
		b[i] = a[i]/2;
		if(i==1){
			L = b[1];
		}
		else{
			L = lcm(L, b[i]);
			if( (L/b[i])%2==0 || L>M ){
				ans = 0;
				printf("%llu\n", ans);
				return 0;
			}
		}
	}
	for(int i=0; ; i++){
		if( L*(2*i+1)>M ) break;
		ans++;
	}

	printf("%llu\n", ans);
	return 0;

}