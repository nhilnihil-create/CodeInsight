#include <bits/stdc++.h>
using namespace std;
vector <int> numbers;
bool condition(int i){
	int max=numbers[i-1], min=max;
	for(int j=i;j<=i+1; j++){
		if(numbers[j]>max) max = numbers[j];
		if(numbers[j]<min) min = numbers[j];
	}
	if (numbers[i] == min || numbers[i] == max) return false;
	return true; 
}

int main(){
	int n, x, cont=0;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >>x;
		numbers.push_back(x);
	}
	for(int i=1;i<n-1; i++){
		if (condition(i)) cont++;
	}
	cout << cont;
	return 0;
}