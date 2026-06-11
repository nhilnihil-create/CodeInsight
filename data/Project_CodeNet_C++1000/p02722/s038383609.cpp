#include <cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
int check(ll n, ll div){
     if(n % div==0)
        return check(n/div, div);
    else  return (n % div == 1) ;
}

int main(){
	ll n;
	int res = 0;

	scanf("%lld", &n);
	for(ll i=2; i*i <= n; i++) {
		if(check(n, i)) {
			res++;
			if(i != n / i && check(n, n/i))
				res++;
		}
	}
	if(n==2)     printf("%d",res+1);
	else      printf("%d",  res+2);

	return 0;
}
