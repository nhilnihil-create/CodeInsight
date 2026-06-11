#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++)
	{
		cin >> a.at(i);
		b.at(i)=a.at(i);
	}
	sort(b.begin(),b.end());
	int mm=b.at(n-1),mn=b.at(n-2);
	for(int i=0;i<n;i++)
	{
		if(a.at(i)==mm)
		{
			cout << mn << endl;
		}
		else
		{
			cout << mm << endl;
		}
	}
}
