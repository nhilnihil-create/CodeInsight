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
	ll N, M, V, P;
	ll A[100000];
	cin >> N >> M >> V >> P;
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	sort(A, A+N);
	
	ll S[100000];
	fill(S, S+N, 0);
	S[0] = A[0];
	for(int i = 1; i < N; i++){
		S[i] = S[i-1] + A[i];
	}
	
	int count = 0;
	for(int i = 0; i < N; i++){
		if(A[N-P] <= A[i]){
			count++;
			continue;
		}
		
		if(N-P-i <= N-V){
			if(A[N-P] <= A[i] + M){
				count++;
			}
			continue;
		}
		
		ll sum = S[N-P]-S[i] - A[i]*(N-P-i);
		if(sum <= (N-V) * M && A[N-P] <= A[i] + M){
			count++;
		}
	}
	cout << count << endl;
	
	return 0;
}