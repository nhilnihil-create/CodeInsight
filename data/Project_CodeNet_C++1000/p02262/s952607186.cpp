#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

long long int cnt;

void insertion_sort(int *data, int n, int g)
{
	for(int i = g; i < n; i++)
	{
		int v = data[i];
		int j = i - g;
		while(j >= 0 && data[j] > v) {
			data[j+g] = data[j];
			j = j-g;
			cnt++;
		}
		data[j+g] = v;
	}
}

void shell_sort(int *data, int n, vector<int> g)
{
	int h = 1;
	while(h <= n) {
		g.push_back(h);
		h = 3*h + 1;
	}

	fprintf(stdout, "%lu\n", g.size());
	for(int i = g.size()-1; i >= 0; i--) {
		fprintf(stdout, "%d", g[i]);
		if(i) printf(" ");
		if(i == 0) printf("\n");
	}

	for(int i = g.size()-1; i >= 0; i--) {
		insertion_sort(data, n, g[i]);		
	}
}

int main(void)
{
	int *data;
	int n;

	cin >> n;
	data = new int[n];

	for(int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}

	vector<int> g;	
	
	shell_sort(data, n, g);
	
	fprintf(stdout, "%lld\n", cnt);
	for(int i = 0; i < n; i++) {
		fprintf(stdout, "%d\n", data[i]);
	}

	delete data;
	return 0;
}
