#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  cin >> a;
  vector<int> vec(a+1);

	for(int i=0;i<a;i++)cin >> vec.at(i);
	for(int i=1;i<a;i++)vec.at(i)+=vec.at(i-1);
	// cout << vec.at(a-1) << endl; 
	int s = vec.at(a-1);
	int M = 1000000;
	for(int i=0;i<a;i++)M = min(M,abs(s-vec.at(i)*2));
	cout << M << endl;
}