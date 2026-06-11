#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin >> n;
	int d[n], max = -1;
	for(int i = 0; i < n; i++){
		cin >> d[i];
		max = max < d[i] ? d[i] : max;
	}
	
	vector<int> pr;
	pr.push_back(2);
	for(int i = 3; i <= sqrt(max); i++){
		for(int j = 0; j < pr.size() && pr[j] <= sqrt(i); j++){
			if(i % pr[j] == 0) goto BREAK;
		}
		pr.push_back(i);
		BREAK:;
	}
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < pr.size() && pr[j] <= sqrt(d[i]); j++){
			if(d[i] % pr[j] == 0) goto BREAK2;
		}
		cnt++;
		BREAK2:;
	}
	cout << cnt << endl;
	return 0;
}