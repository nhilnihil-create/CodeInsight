#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring> 

using namespace std;

int func(int m, int l);

int main()
{
	int n, ans;
	while(1){
		cin >> n;
		if(n == 0) break;
		if(n == 1) ans = 1;
		else {
			if(n % 2 == 0) ans = func(n + 1, n);
			else ans = func(n+2, n);
		}
		cout << ans << endl;
	}
	return 0;
}

int func(int m, int l)
{
	int cnt=0, a;
	for(int i = 0; (m + (2 * i)) <= 2 * l; i++){
		a = m + (2 * i);
		int j=2;
		while(1){
			if(j * j > a){
				cnt++;
				break;
			}
			else if(a % j == 0) break;
			else j++;
		}
	}
	return cnt;
}