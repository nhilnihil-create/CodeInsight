#include <bits/stdc++.h>
using namespace std;

int n, display;
int main()
{
	cin >> n >> display;
  	int inner = display + 100*max(0, 10-n);
  	cout << inner << endl;
	return 0; 
}