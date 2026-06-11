#include<iostream>
#include<cmath>
#define MAX 247000
using namespace std;
bool arr[MAX];
void Era(){
	for(int i = 0; i <= MAX; i++){
		arr[i] = true;
	}
	for(int i = 2; i <= sqrt(MAX); i++){
		if(arr[i]){
			for(int j = 0; i * (j + 2) <= MAX; j++){
				arr[i *(j + 2)] = 0;
			}
		}
	}
}
int Eratosthenes(int N){
	int cnt=0;
	for(int i = N+1; i <= N*2; i++){
		if(arr[i]){
			//cout << i << endl;
			cnt++;
		}
	}
	return cnt;
}
int main(){
	Era();
	while(1){
		int n;
		cin >> n;
		if(n==0)	break;
		else	cout << Eratosthenes(n) << endl;
	}
	return 0;
}
