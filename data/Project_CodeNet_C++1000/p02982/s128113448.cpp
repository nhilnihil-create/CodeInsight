#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;
bool isIntDistance(vector<int> a,vector<int> b){
	double distance = 0;
	for(int i = 0; i < a.size(); i++){
		distance += (a[i] - b[i])*(a[i] - b[i]);
	}
	int d2 = sqrt(distance);
	//cout<<d2*d2<<":"<<distance<<endl;
	if( abs(d2*d2 - distance) <= 0.0000001){
		return true;
	}else{
		return false;
	}
}

int main(){
	int n,d;
	cin>>n>>d;
	vector<vector<int>> x(n);
	for(int i = 0; i < n; i++){
		x[i] = vector<int>(d);
		for(int j = 0; j < d; j++){
			cin>>x[i][j];
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i ++){
		for(int j = i + 1; j < n; j++){
			if( isIntDistance(x[i],x[j]) == true) ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
