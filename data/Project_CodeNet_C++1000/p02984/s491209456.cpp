#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> x(n);
	ll sum = 0;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		if( i % 2 == 0){
			sum += a[i];
		}else{
			sum -= a[i];
		}
	}
	x[0] = sum / 2;
	for(int i = 1; i < n; i++){
		x[i] = a[i-1] - x[i-1];
	}
	for(int i = 0; i < n; i++){
		cout<<2*x[i]<<" ";
	}
	cout<<endl;
	return 0;
}

