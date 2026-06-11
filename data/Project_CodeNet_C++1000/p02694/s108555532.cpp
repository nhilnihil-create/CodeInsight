#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <ctype.h>
#include <stdlib.h>
#include <map>
using namespace std;

int main()
{
	long long X;
	cin >> X;
	long long total = 100;
	
	int i = 0;
	while(total < X){
		 total += total / 100;
		 //cout << total << endl;
		i++;
	}
	cout << i << endl;
}


