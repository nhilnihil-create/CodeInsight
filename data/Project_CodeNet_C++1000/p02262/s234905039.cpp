#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <bitset>
using namespace std;
#define len(n) (int)n.length()
#define dump cout
#define pb push_back
#define ll long long

int CNT = 0;

vector<int> MakeG(int n)
{
	vector <int> g;
	g.pb(1);
	for (int i=1;;i++)
	{
		int elem = 3 * g[i-1] + 1;
		if (elem > n)
			break;
		g.pb(elem);
	}
	return g;
}

void InsertionSort(int* A, int n, int g)
{
	for (int i = g; i < n; i++) {
	    int v = A[i];
		int j = i - g;
		while ((j >= 0) && (v < A[j]))
		{
			A[j+g] = A[j];
			j -= g;
			CNT++;
		}
		A[j+g] = v;
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	int *A = new int[n];
	for (int i = 0; i < n; i++) {
	    cin >> A[i];
	}
	
	vector<int> g = MakeG(n);
	
	cout << g.size() << endl;
	for (auto itr = g.rbegin(); itr != g.rend(); ++itr) {
	    InsertionSort(A, n, *itr);
		cout << *itr << " ";
	}
	cout << endl << CNT << endl;
	
	for (int i = 0; i < n; i++) {
	    cout << A[i] << endl;
	}
	
	
	delete[] A;
	return 0;
}