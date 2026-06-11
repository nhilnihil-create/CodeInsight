#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define NMAX 200002
using namespace std;
vector<int >v;
int N,K,M = 0,m = 0,ans = 0;
bool able(int a){
	int cou = 0;
	for(auto&& i : v) {
		int b = i;
		if(b <= a) break;
		if(b>a){
			cou = cou + b/a - (b%a == 0);
		}
	}
	// cout << a << ":" << cou << endl;
	if(cou > K) return false;
	else return true;
}
int main(){
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		int a;
		cin >> a;
		v.push_back(a);
		M = max(M,a);
	}
	sort(v.begin(), v.end(),greater<int>());
	while(M - m > 1){
		int k = (M+m)/2;
		if(able(k)) M = k;
		else m = k;
	}
	cout << M << endl;
}