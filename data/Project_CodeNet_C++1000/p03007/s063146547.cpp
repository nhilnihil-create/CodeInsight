#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int A[100010];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A, A + N);
	vector<pair<int,int>> V;
	int num1 = A[0], num2 = A[N - 1];
	for (int i = 1; i < N - 1; i++) {
		if (A[i] < 0) {
			V.push_back({ num2,A[i] });
			num2 -= A[i];
		}
		else {
			V.push_back({ num1,A[i] });
			num1 -= A[i];
		}
	}
	V.push_back({ num2,num1 });
	cout << num2 - num1 << endl;
	for (pair<int, int> P : V) {
		cout << P.first << " " << P.second << endl;
	}
}
