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
	long long n,a,b;
	cin >> n >> a >> b;
	
	long long cost_win,cost_lose,cost_cent;
	
	if((b-a)%2==0){
		cost_cent=abs(b-a)/2;
		cout << cost_cent << endl;
		return 0;
	}
	
	cost_win=a+(b-a-1)/2;
	cost_lose=n-b+1+(b-a-1)/2;
	
	long long min_cost=min(cost_win,cost_lose);
	cout << min_cost << endl;
	return 0;
}
