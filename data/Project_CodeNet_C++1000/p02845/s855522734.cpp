#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <functional>
#include <queue>
#include <unordered_set>
#include <climits>
#include <set>
#include <list>
#include <cmath>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
	const ll mod = 1000000007;
	ll N;
	ll A[100001];
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	
	ll ans = 1;
	ll hat[3];
	fill(hat, hat+3, 0);
	for(int i = 0; i < N; i++){
		int degree = 0;
		// 番号iの帽子がなりうる色数を数える
		for(int c = 0; c < 3; c++){
			if(A[i] == hat[c]){
				degree++;
			}
		}
		
		// 番号iの帽子の色を決め打つ
		for(int c = 0; c < 3; c++){
			if(A[i] == hat[c]){
				hat[c]++;
				break;
			}
		}
		ans *= degree;
		ans %= mod;
	}
	cout << ans << endl;
	
	return 0;
}