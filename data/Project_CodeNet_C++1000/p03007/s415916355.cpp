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

using namespace std;
typedef long long ll;

int main()
{
	ll N;
	vector<int> A;
	cin >> N;
	for(int i = 0; i < N; i++){
		ll a;
		cin >> a;
		A.push_back(a);
	}
	
	sort(A.begin(), A.end());
	
	vector<ll> first;
	vector<ll> second;
	
	while(A.size() >1 ){
		int a = A.back();
		int a_ = A[A.size()-2];
		if(a > 0 && a_ > 0){
			A.pop_back();
			first.push_back(A.front());
			second.push_back(a);
			A.front() -= a;
		}else{
			int b = A.front();
			A.erase(A.begin(), A.begin()+1);
			first.push_back(A.back());
			second.push_back(b);
			A.back() -= b;
		}
	}
	
	cout << A[0] << endl;
	for(int i = 0; i < first.size(); i++){
		cout << first[i] << " " << second[i] << endl;
	}
	
	return 0;
}