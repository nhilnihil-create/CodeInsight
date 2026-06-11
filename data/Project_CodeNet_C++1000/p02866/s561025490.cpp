#include <iostream>
#include <math.h>
#define Max 200000
#define Mod 998244353
using namespace std;
long long ans = 1;
int N,D[Max], a[Max];
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++){
		cin >> D[i];a[D[i]]++;
	}
	if (D[1] != 0)ans = 0;
	for (int j = 2; j <= N; j++){
		ans = ((ans)%Mod * (a[D[j] - 1] % Mod)) % Mod;
	}
	cout << ans%Mod;
}