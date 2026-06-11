#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef unsigned long long ll;


int main()
{
	int n,x;
	cin>>n>>x;
	int *D = new int[n+1];
	D[0] = 0;
	rep(i,n){
		int l;
		cin>>l;
		D[i+1] = D[i] + l;
	}
	int bound = 0;
	for(int i = 0; i <= n; i++){
		if( D[i] <= x) bound++;
	}
	cout<<bound<<endl;
	
	return 0;
}

