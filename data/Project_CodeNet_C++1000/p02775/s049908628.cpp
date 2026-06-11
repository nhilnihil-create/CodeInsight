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
	string S;
	cin >> S;
	int N[1000001];
	fill(N, N+1000001, 0);
	for(int i = 0; i < S.length(); i++){
		N[i] = S[S.length()-1-i] - '0';
	}
	
	ll ans = 0;
	for(int i = 0; i <= S.length(); i++){
		if(N[i] == 5 && N[i+1] >= 5){
			N[i+1]++;
			ans += 10-N[i];
		}
		else if(N[i] <= 5){
			ans += N[i];
		}
		else if(N[i] == 10){
			N[i+1]++;
		}
		else{
			N[i+1]++;
			ans += 10-N[i];
		}
	}
	
	cout << ans << endl;
	
	return 0;
}