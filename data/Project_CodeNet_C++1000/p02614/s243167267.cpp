#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <climits>
#include <tuple>
#include <queue>
#include <cassert>
#include <set>
//#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define el '\n'
 

 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n,m,k;
	cin >>n>>m>>k;
	vector<vector<char> > gr(n, vector<char>(m));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> gr[i][j];
		}
	}


	ll sol = 0;

	for (int i = 0;  i < (1 << (n )); i++){
		for (int j = 0; j < (1 << (m )); j++){

			int l = 0;
			for (int x = 0; x < n; x++){
				for (int y = 0 ; y < m; y++){
					int X = 1 << x, Y = 1 << y;
					if (X & i ||  Y & j) continue;
					if (gr[x][y] == '#'){
						
						l++;
					}
				}
			}

			if (l == k){
				sol ++;
			}
		}
	}

	cout << sol<<el;
    return 0;
}