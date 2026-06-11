#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin >> a >> b;
  vector<int> vec(a);
	int ans =0;
	for(int i=0;i<a;i++)cin >> vec.at(i);
	for(int i=1;i<a;i++)vec.at(i)+=vec.at(i-1);
	for(int i=0;i<a;i++)if(vec.at(i)<=b)ans++;
	cout << ans + 1<< endl;
}