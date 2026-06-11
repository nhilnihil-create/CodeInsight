#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int N,K;
vector<int> v;

int main (){
	cin >> N >> K;
	int cnt = 0;
	
	for(int i=0;i<N;i++){
		int x;
		cin >> x;
		if(x >= K) cnt++;
	}
	cout << cnt << endl;
	return 0; 
}