#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
	int a[101] = {};
	int in, maxa=0;
	while (cin >> in, !cin.eof()){
		a[in]++;
	}
	for (int i = 0; i < 101; i++){
		maxa = max(maxa, a[i]);
	}
	for (int i = 0; i < 101; i++){
		if (a[i] == maxa){
			cout << i << endl;
		}
	}

	return 0;
}