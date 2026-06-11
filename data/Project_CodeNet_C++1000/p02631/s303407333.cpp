#include<iostream>
using namespace std;

int main(){
	int n;
  	cin >> n;
  	int a[n] = {};
   	for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
   	
  	int x = 0;
  	for(int i = 0; i < n; i++){
    	x = x ^ a[i];
    }
  
  	for(int i = 0; i < n; i++){
    	a[i] = x ^ a[i];
    }
  	
  	for(int i = 0; i < n; i++){
    	cout << a[i] << " ";
    }
  	cout << endl;
}