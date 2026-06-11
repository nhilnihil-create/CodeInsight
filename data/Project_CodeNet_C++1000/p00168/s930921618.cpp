#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <ctime>
#include <cstring>
using namespace std;

int n;
int way[30];

int main(void){

	cin >> n;
	while(n != 0){

		for(int i = 0; i < n; i++){
			way[i] = 0;
		}
		
		way[0] = 1;
		way[1] = 2;
		way[2] = 4;

		for(int i = 3; i < n; i++){
			way[i] = way[i - 1] + way[i - 2] + way[i - 3];
		}

		double ans = way[n - 1] / 3650.0;

		cout << ceil(ans) << endl;

		cin >> n;
	}

    return 0;
}