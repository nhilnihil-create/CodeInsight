#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	int nd = (N + 1) / 2;
	double na = N, nb = nd;
	nb /= na;
	printf("%.8f\n", nb);
}