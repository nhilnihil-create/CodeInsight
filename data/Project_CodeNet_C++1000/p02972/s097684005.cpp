#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <numeric>
#include <queue>
#include <numeric>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <map>
#include <functional>
#include <limits>
#include <set>
#include <stack>
#define rep(i,a,b) for((i)=a;i<(int)(b);i++)
#define Max(a,b) ((a) < (b) ? (b) : (a))
#define Min(a,b) ((a) > (b) ? (b) : (a))
#define AAA (1000000007)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pairII;


ll gcd(ll a, ll b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}


int main() {
	int i, j, k;
	
	int N, M, K;

	int B[200001];
	int S[200001] = { 0 };
	cin >> N;
//	N = 200000;
	rep(i, 1, N + 1) {
		cin >> B[i];
		//B[i] = 1;
	}
	int Ans[200001] = { 0 };
	for (i = N; i > 0; i--)
	{
		if (S[i] % 2 != B[i]) {
			Ans[i] = 1;
		}
		if (Ans[i] == 0)
			continue;
		bool isAdd[200001] = { false };
		int I = i;
		int J = sqrt(i) + 1;
		S[1]++;
		isAdd[1] = true;
		for (j = 2; j <= J; )
		{
			if (!isAdd[I]) {
				S[I] += 1;
				isAdd[I] = true;
			}
			if (I % j == 0) {
				if (!isAdd[j]) {
					S[j] += 1;
					isAdd[j] = true;
				}

				I /= j;

			}
			else
				j++;
		}
		if (!isAdd[I] && I != i) {
			S[I] += 1;
		}
	}

	vector<int> ans;
	rep(i, 1, N + 1) {
		if (Ans[i] == 1) {
			ans.push_back(i);
		}
	}

//	cout << ans.size() << endl;
//	for (auto& x : ans) {
//		cout << x << " ";
//	}
		
	vector<int> result;
	int AA[200001] = { 0 };
	int aa[200001] = { 0 };
	for (i = N; i >0 ; i--)
	{
		for (j = i; j <= N; j+=i)
		{
			AA[i] ^= aa[j];
		}
		if (AA[i] % 2 != B[i]) {
			aa[i] = 1;
			result.push_back(i);
		}
	}
	cout << result.size() << endl;
	for (auto& x : result)
		cout << x << " ";

	return 0;

}
