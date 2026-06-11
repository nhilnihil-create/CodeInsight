#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	
	vector<int> An(N);
	for(int i = 0; i < N; i++){
		cin >> An.at(i);
	}
	
	int c = 0;
	int d;
	for(int i = 0; i < N; ){
	d = An.at(i);
	
	if(d%2 == 1)
		c++;
		
	i = i + 2;
	}
	
	cout << c << endl;
}