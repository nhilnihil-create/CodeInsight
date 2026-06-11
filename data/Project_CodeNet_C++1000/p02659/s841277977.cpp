#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	unsigned long long a;
	double b;
	cin>> a >>b;
    b += 0.001;
	unsigned long long c = (unsigned long long)(100*b)*a/100;
	cout<< c <<endl;
}