#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;
#define MAX_N 1000001

bool divisible[MAX_N];
bool visited[MAX_N];
void init(){
	rep(i,MAX_N){
		divisible[i] = false;
		visited[i] = false;
	}
}

int A[MAX_N];

int main(){
	init();
	int n;
	cin>>n;
	rep(i,n){
		cin>>A[i];
	}
	sort(A,A+n);
	for(int i = 0; i < n; i++){
		if( divisible[A[i]] == false && visited[A[i]] == true){
			divisible[A[i]] = true;
		}else if( divisible[A[i]] == false && visited[A[i]] == false){
			visited[A[i]]   = true;
			for(int j = 2; A[i]*j <= MAX_N; j++){
				divisible[A[i]*j] = true;
			}
		}
	}
	int ans = 0;
	rep(i,n){
		if( divisible[A[i]] == false) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
