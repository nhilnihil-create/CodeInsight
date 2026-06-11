#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159265358979323846264338327950L

int main(void) {
	long long N, K, A,tmp;


	cin >> N >> K;

	vector<long long> light(N), light_tmp(N+1, 0), reset(N, 0);

	for (long long i = 0; i < N; i++) {
		cin >> A;
		light[i] = A;

	}

	for (long long i = 0; i < min(K,(long long) 41 ); i++) {
		light_tmp = reset;
		for (long long j = 0; j < N; j++) {

			// for (long long s = j - light[j]; s <= j + light[j] + 0.5; s++) {
			// 	if (s < 0) { continue; }
			// 	if (s >= N ) { continue; }

			// 	light_tmp[s]++;
			// }
            tmp = max((long long)0,j - light[j]);
            light_tmp[tmp]++;

            tmp=min(j + light[j]+1,N+1);
            light_tmp[tmp]--;
		}
		
        light[0]=light_tmp[0];
        for(long long j=1;j<N;j++){
            light[j] = light[j-1] + light_tmp[j] ;
        }
	}


	for (long long i = 0; i < N - 1; i++) {
		cout << light[i] << " ";
	}
	cout << light[light.size() - 1] << endl;



	return 0;
}

