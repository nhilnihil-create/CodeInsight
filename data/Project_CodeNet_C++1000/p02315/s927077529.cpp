#include <cstdio>
#include <iostream>
#include <cmath>
#include <ctype.h>
#include <string> 
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <iomanip>
  
using namespace std;

#define pi 3.141592653589793

int solve(int n, int maxw, int v[], int w[])
{
	int result[101][10001];
	for(int i = 0; i < n + 1; i++){
		for(int j = 0; j < maxw + 1; j++){
			result[i][j] = 0;
		}
	}
	for(int i = 1; i < n + 1; i++){
		for(int j = 1; j < maxw + 1; j++){
			if(w[i] <= j){
				result[i][j] = max(result[i - 1][j], result[i - 1][j - w[i]] + v[i]);
			} else result[i][j] = result[i - 1][j];
		}
	}
	return result[n][maxw];
}

int main()
{
	int n, maxw;
	int v[101], w[101];
	cin >> n >> maxw;
	for(int i = 1; i < n + 1; i++){
		cin >> v[i] >> w[i];
	} 
	cout << solve(n, maxw, v, w) << endl;
	return 0;
}