#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<math.h>
#include<queue>
#include <algorithm>
#include<functional>
#include<cstdlib>
#include<cmath>


#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define CI cin >>
#define CO cout <<
#define E << endl;

using namespace std;

typedef pair<int, int> P;
typedef pair<long, long> LP;
typedef pair<int, P> PP;
typedef pair<long, LP> LPP;

int N;

int dy[] = { 0, 0, 1, -1, 0 };
int dx[] = { 1, -1, 0, 0, 0 };

int ball[10];

//int B = 0, C = 0;

int bfs(int n, int B, int C) {
	
	if (n == 10) {
		return true;
	}

	if (B < ball[n]) {
		B = ball[n];
		return bfs(n + 1, B, C);
	}
	if (C < ball[n]) {
		C = ball[n];
		return bfs(n + 1, B , C);
	}
	
	return false;

}

void input(void) {
	for (int i = 0; i < 10; i++) {
		CI ball[i];
	}
	return;
}


int main(void) {
	CI N;

	for (int i = 0; i < N; i++) {
		input();
		if (bfs(0, 0, 0)) {
			CO "YES" E
		}
		else {
			CO "NO" E
		}
	}
	
	return 0;
}