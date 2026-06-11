#include<iostream>
using namespace std;
 
int main(void){
	int n;
	int a = 0;
  	cin >> n;
  	for(int i = 1; i < n; i++){
    	a = a + (n-1)/i;
    }
	cout << a << endl;
}