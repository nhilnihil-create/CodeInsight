#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
using namespace std;

int n, *ns;

bool isMa(int num, int cur, int i){
	if(i == n) return false;
	if(cur + ns[i] == num) return true;
	else return isMa(num, cur, i+1) || isMa(num, cur+ns[i], i+1);
}

int main() {
	scanf("%d", &n);
	ns = new int[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &ns[i]);
	}
	
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; i++){
		int qNum;
		scanf("%d", &qNum);
		printf("%s\n", isMa(qNum, 0, 0) ? "yes" : "no");
	}
	
    return 0;
}