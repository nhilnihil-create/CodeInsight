#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <ctype.h>
#include <ctime>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <numeric>
#include <complex>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;
#define MAX 100
#define WHITE 1
#define GRAY 2
#define BLACK 3

int n;
int graph[MAX][MAX];
stack<int> st;
int *d,*f,*v;
int *color;
int t = 0;

int next(int k){
	for(int i = v[k];i < n;i++){
		v[k]++;
		if(color[i] == WHITE && graph[k][i] == 1) return i;
	}
	return -1;
}

void dfs(int k){
	for(int i = 0;i < n;i++) v[i] = 0;

	st.push(k);
	d[k] = ++t;
	color[k] = GRAY;

	while(!st.empty()){
		int m = next(st.top());
		if(m != -1){
		  if(color[m] == WHITE){
				st.push(m);
				color[m] = GRAY;
				d[m] = ++t;
			}
		}else{
			f[st.top()] = ++t;
			color[st.top()] = BLACK;
			st.pop();
		}
	}
}


int main(){
	cin >> n;
	//?????????
	color = new int[n];
	d = new int[n];
	f = new int[n];
	v = new int[n];
	for(int i = 0;i < n;i++){
		color[i] = WHITE;
		d[i] = 0;
		f[i] = 0;
		for(int j = 0;j < n;j++){
			graph[i][j] = 0;
		}
	}
	//data input
	for(int i = 0;i < n;i++){

		int t,k,p;

		cin >> t >>  k;
		for(int j = 0;j < k;j++){
			cin >> p;
			p--;
			graph[i][p] = 1;
		}
	}
	for(int i = 0;i < n;i++){if(color[i] == WHITE) dfs(i);}
	for(int i = 0;i < n;i++){
		cout << i+1 << " " << d[i] << " " << f[i] << endl;
	}
	return 0;
}