#include <iostream>
#include <cmath>
#include <cstdlib>
 
using namespace std;
 
int main(){
         
	int n;
	cin >> n;
	
	int * X;
	int * Y;
	
	X = new int [n];
	Y = new int [n];
	
	for(int i = 0; i < n; i++){cin >> X[i];}
	for(int i = 0; i < n; i++){cin >> Y[i];}
	
	for(int i = 0; i < 3; i++){
		double sum;
		sum = 0;
		for(int j = 0; j < n; j++){
			sum += pow(abs(X[j] - Y[j]),i+1);
		}
		cout << fixed << pow(sum,(1.0/(i+1.0))) << endl;
	}
	
	double max;
	max = 0;
	for(int i = 0; i < n; i++){
		if(max < abs(X[i] - Y[i])){
			max = abs(X[i] - Y[i]);
		}
	}
	cout << fixed << max << endl;
	
	delete[] X;
	delete[] Y;
}