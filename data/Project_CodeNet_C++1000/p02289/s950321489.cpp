#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
using namespace std;

void maxHeap(int* keys, int size, int cur){
	if(cur*2 > size){
		// noop
	}else if(cur*2+1 > size && keys[cur*2] > keys[cur]){
		swap(keys[cur*2], keys[cur]);
	}else{
		int l = keys[cur*2];
		int r = keys[1+cur*2];
		if(l > r && l > keys[cur]){
			swap(keys[cur*2], keys[cur]);
			maxHeap(keys, size, cur*2);
		}else if(r > keys[cur]){
			swap(keys[1+cur*2], keys[cur]);
			maxHeap(keys, size, 1+cur*2);
		}
	}
}
void fixHeap(int* keys, int cur){
	if(cur/2 >= 1 && keys[cur] > keys[cur/2]){
		swap(keys[cur], keys[cur/2]);
		fixHeap(keys, cur/2);
	}
}

int main() {
	int node = 0;
	int keys[2000000];
	for(;1;){
		char *com = new char[16];
		scanf("%s", com);
		
		if(com[0] == 'i'){
			scanf("%d", &keys[++node]);
			fixHeap(keys, node);
		}else if(com[1] == 'x'){
			printf("%d\n", keys[1]);
			keys[1] = keys[node--];
			maxHeap(keys, node, 1);
		}else break;
	}
	
	return 0;
}