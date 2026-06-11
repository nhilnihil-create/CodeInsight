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
#define MAX_N 200001
using namespace std;
typedef long long int ll;

ll visited[MAX_N];

void init(){
	for(int i = 0; i < MAX_N; i++){
		visited[i] = -1;
	}
}


int main(){
	init();
	int n;
	ll k;
	cin>>n>>k;
	vector<ll> A(n+1);
	for(int i = 1; i <= n; i++){
		cin>>A[i];
	}
	ll count = 0;
	int now = 1;
	int previous = 1;
	while(visited[now] == -1){
		visited[now] = count;
		count++;
		previous = now;
		now = A[now];
	}
	ll offset = visited[now];
	ll loop = visited[previous] - visited[now] + 1;
	now = 1;
	if( k <= offset){
		for(int i = 0; i < k; i++){
			now = A[now];
		}
	}else{
		for(int i = 0; i < offset + ((k-offset) % loop);i++){
			now = A[now];
		}
	}
	cout<<now<<endl;
	//cout<<"offset:"<<offset<<",loop:"<<loop<<endl;
	return 0;
}
