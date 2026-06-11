#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int n, s;

int part(int index, int count, int sum){
	if(index == 10){
		if(count == n && sum == s){
			return 1;
		}
		return 0;
	}
	return part(index + 1, count, sum) + part(index + 1, count + 1, sum + a[index]);
}

int main(){
	
	while(true){
		
		cin >> n >> s;
		
		if(n == 0){
			break;
		}
		
		cout << part(0, 0, 0) << endl;
		
	}
	
	return 0;
}