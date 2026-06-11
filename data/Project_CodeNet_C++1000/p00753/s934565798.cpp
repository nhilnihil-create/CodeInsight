// 2012/05/14 Tazoe

#include <iostream>
using namespace std;

void eratos(bool prime[], int n)
{
	if(n>=1){
		prime[0] = false;
	}
	if(n>=2){
		prime[1] = false;
	}

	for(int i=2; i<n; i++){
		prime[i] = true;
	}

	for(int i=2; i*i<n; i++){
		if(!prime[i])
			continue;

		for(int j=i+i; j<n; j+=i){
			prime[j] = false;
		}
	}
}

int main()
{
	bool P[246913];
	eratos(P, 246913);

	while(true){
		int n;
		cin >> n;

		if(n==0)
			break;

		int cnt = 0;
		for(int i=n+1; i<=2*n; i++){
			if(P[i]){
				cnt++;
			}
		}

		cout << cnt << endl;
	}

	return 0;
}