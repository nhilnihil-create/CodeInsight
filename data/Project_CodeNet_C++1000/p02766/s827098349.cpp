#include<stdio.h>
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
	int N;
	int R;
	cin >> N>>R;
	int i;
	i = 0;
	while (pow(R,i)<=N){
		i++;
	}
	cout << i << endl;
}