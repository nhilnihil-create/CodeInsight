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
int H;
int *T;
int parent(int i){return i / 2;}
int left(int i){return 2 * i;}
int right(int i){return 2 * i + 1;}

void maxHeapify(int *A,int i){
	int l = left(i);
	int r = right(i);
	int largest = i;
	if(l <= H && A[l] > A[i]){
		largest = l;
	}
	if(r <= H && A[r] > A[largest]){
		largest = r;
	}
	if(largest != i){
		swap(A[i],A[largest]);
		maxHeapify(A,largest);
	}
}

int main(){
	cin >> H;
	T = new int[H+1];
	for(int i = 1;i <= H;i++) cin >> T[i];
	for(int i = H/2;i >= 1;i--) maxHeapify(T,i);
	for(int i = 1;i <= H;i++){
		if(i != H) cout << " " << T[i];
		else cout << " " << T[i] << endl;
	}
	return 0;
}