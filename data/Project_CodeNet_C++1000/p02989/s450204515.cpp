#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	vector<int> vd;

	cin >> N;
	for(int i=0; i<N; i++){
		int d;
		cin >> d;
		vd.push_back(d);
	}

	sort(vd.begin(), vd.end());

	int r = N / 2 ;
	int l = r - 1;
	int ans = vd[r] - vd[l];
	cout << ans << endl ;
	return 0;
}