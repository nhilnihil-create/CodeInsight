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
	int N,L;
	cin>>N>>L;
	int plan = 0;
	for(int i = 0; i < N; i++){
		int aji = L + i;
		plan += aji;
	}
	int ans = plan;
	int minDiff = 10000000;
	for(int i = 0; i < N; i++){
		int aji = L + i;
		if( abs((plan - aji) - plan) < minDiff){
			ans = plan - aji;
			minDiff = abs( (plan-aji) - plan);
		} 
	}
	cout<<ans<<endl;
	return 0;
}

