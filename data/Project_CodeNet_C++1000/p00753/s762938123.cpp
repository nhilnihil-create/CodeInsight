#include<stdio.h>
#include<cstdio>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<string.h>
#include<string>
#include<utility>
#include<queue>
#include<stack>
#include<set>
#define pi 3.14159
#define Inf (int)pow(2., 12.)

using namespace std;
typedef std::pair<int, int> mypair;
queue<mypair> qu;
#define M 1000000
const int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
#define N 123456 
int num = 0;


int main(){
	int a[2*N+1];
	for(int i = 0; i <= 2*N; i++) {
		a[i] = i;
	}
	a[1] = 0;
	for(int i = 2; i*i <= 2*N; i++) {
		if(a[i] != 0) {
			for(int j = 2*i; j <= 2*N; j++) {
				if(j % i == 0) a[j] = 0;
			}
		}
	}
	int n;
	while(1) {
		int count = 0;
		cin >> n;
		if(n == 0) break;
		for(int i = n+1; i <= 2*n; i++) {
			if(a[i] != 0) count++;
		}
		cout << count <<endl;
	}
	
	return 0;
}