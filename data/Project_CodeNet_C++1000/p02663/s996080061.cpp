#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	int h1,h2,m1,m2;
	int k;
	cin>>h1>>m1>>h2>>m2>>k;
	cout<<max(0,(h2-h1)*60+(m2-m1)-k);
	return 0;
}