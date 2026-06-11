#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include<cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<iostream>
#include<list>
#include<queue>
#include<set>
#include<string>
#include <vector>

#define ll long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)   FOR(i,0,n)
#define FORL(i,a,b) for(ll i=(a);i<(b);++i)
#define REPL(i,n) FORL(i,0,n)
#define FORR(i,a,b) for(int i=(a);i>=(b);--i)
#define REPR(i,n)   RFOR(i,n,0)

using namespace std;

struct Vertex{
	int parent;
	int depth;
	string type;
	list<int> children;
};

int main(){
	int n, k, tmp, num, parnt;
	Vertex u[100000];
	scanf("%d", &n);
	REP(i, n){
		u[i].parent = -1;
	}
	REP(i, n){
		scanf("%d %d", &num, &k);
		REP(j, k){
			scanf(" %d", &tmp);
			u[num].children.push_back(tmp);
			u[tmp].parent = num;
		}
	}

	

	REP(i, n){
		if (u[i].parent == -1){
			u[i].type = "root";
			parnt = i;
		}
		else if (u[i].children.size() == 0){
			u[i].type = "leaf";
		}
		else{
			u[i].type = "internal node";
		}
	}

	

	REP(i, n){
		int d = 0, p = i;
		while (p != parnt){
			d++;
			p = u[p].parent;
		}
		u[i].depth = d;
	}

	
	//node id : parent = p, depth = d, type, [c1...ck]
	REP(i, n){
		printf("node %d: parent = %d, depth = %d, ", i, u[i].parent, u[i].depth);
		cout << u[i].type << ", [";
		for(auto j = u[i].children.begin(); j != u[i].children.end(); ++j){
			if (j != u[i].children.begin()){
				printf(", ");
			}
			cout << *j;
		}
		printf("]\n");
	}

	return 0;
}
