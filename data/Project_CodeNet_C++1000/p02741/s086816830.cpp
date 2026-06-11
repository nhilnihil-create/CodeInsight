#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    int arr[32];
    stringstream ss("1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51");
    int a;
    char b;
    for(int i = 0; i < 32; i++)
    {
    	ss >> a;
    	arr[i] = a;
    	ss >> b;
	}
	int k; cin >> k;
	cout << arr[k-1];
	
    
    
}