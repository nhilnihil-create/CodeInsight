#include <iostream>
#include<algorithm>
using namespace std;
int main(){
	int n, k,p[1010],a=0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	sort(p, p + n);
	for (int i = 0; i < k; i++)
		a += p[i];
	cout << a;
}