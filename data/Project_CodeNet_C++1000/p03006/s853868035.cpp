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

using namespace std;
typedef long long ll;

struct PQ{
	ll p;
	ll q;
};

int main()
{
	int N;
	ll X[50];
	ll Y[50];
	
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> X[i] >> Y[i];
	}
	
	if( N == 1){
		cout << "1" << endl;
		return 0;
	}
	
	vector<PQ> pqs;
	for(int i = 0; i < N-1; i++){
		for(int j = i+1; j < N; j++){
			ll p = (X[i] - X[j]);
			ll q = (Y[i] - Y[j]);
			PQ pq;
			pq.p = p;
			pq.q = q;
			pqs.push_back(pq);
		}
	}
	
	int ans = 9999999;
	for(int i = 0; i < pqs.size(); i++){
		PQ pq = pqs[i];
		bool Done[50];
		for(int j = 0; j < N; j++){
			Done[j] = false;
		}
		
		int count = 0;
		for(int j = 0; j < N; j++){
			if(!Done[j]){
				count++;
				PQ xy = {X[j], Y[j]};
				vector<PQ> xys;
				xys.push_back(xy);
				
				for(int r = 0; r < N; r++){
					for(int k = j+1; k < N; k++){
						if(Done[k]){
							continue;
						}
						for(int XY = 0; XY < xys.size(); XY++){
							if(((xys[XY].p-X[k]) == pq.p && (xys[XY].q-Y[k]) == pq.q) || ((xys[XY].p-X[k]) == -pq.p && (xys[XY].q-Y[k]) == -pq.q)){
								Done[k] = true;
								PQ xy2 = {X[k], Y[k]};
								xys.push_back(xy2);
								break;
							}
						}
					}
				}
			}
		}
		ans = min(ans, count);
		// cout << pq.p << " " << pq.q  << " : " << count << endl;
	}
	
	cout << ans << endl;
	
	return 0;
}
