#include<iostream>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<algorithm>//min,max,swap,rand,reverse,sort,lower_bound
#include<functional>
#include<vector>
#include<list>
#include<map>
#include<tuple>
#include<cmath>//abs, sin, cos
#include<bitset>
using namespace std;

int main()
{
	int N, t, maxi=0;
	vector<int> A, A_copy;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> t;
		A_copy.push_back(t);
	}
	int first, second;
	A = A_copy;
	sort(A.begin(), A.end());
	reverse(A.begin(), A.end());
	first = A[0];
	second = A[1];

	for (int i = 0; i < N; i++) {
		if (A_copy[i] == first)
			cout << second << endl;
		else
			cout << first << endl;
	}

	return 0;
}