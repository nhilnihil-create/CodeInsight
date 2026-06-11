#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >>n;

	vector<int> l(n);
	for(int i = 0; i < n; ++i)
		cin >>l[i];
	int cnt = 0;
	sort(begin(l), end(l));
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			for(int k = j + 1; k < n; ++k){
				if(l[i] == l[j] || l[i] == l[k] || l[j] == l[k])
					continue;
				if(l[i] + l[j] > l[k])
					++cnt;
			}
		}
	}
	cout <<cnt <<'\n';
	return 0;
}
