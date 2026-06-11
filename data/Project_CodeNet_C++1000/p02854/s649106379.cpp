#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>

#define MOD 1e9+7;
#define INF 1e17+9;
#define PI acos(-1);

using namespace std;

int main(){
	long long n;
	cin >> n;
	vector<long long> a(n);
	long long sum=0;
	for(long long i=0;i<n;i++){
		cin >> a[i];
		sum+=a[i];
	}
	long long cent=sum/2;
	long long left,right;
	left=right=0;
	long long cost=INF;
	for(long long i=0;i<n;i++){
		left+=a[i];
		right=sum-left;
		cost=min(cost,abs(right-left));
	}
	cout << cost << endl;
	return 0;
}
