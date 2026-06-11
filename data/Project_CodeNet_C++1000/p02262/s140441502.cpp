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

int *S;
int n;
int cnt = 0;
stack<int> pattern,patterncopy;

void insertsort(int g){
	int a,b,c;
	for(int i = g;i < n;i++){
		a = S[i];
		b = i - g;
		while(b >= 0 && S[b] > a){
				S[b+g] = S[b];
				b -= g;
				cnt++;
		}
		S[b+g] = a;
	}
}

void makeprogression(){
	for(int m = 1;;){

		if(m > n) break;

		pattern.push(m);
		patterncopy.push(m);
		m = 3*m + 1;

	}
}

int main(){
	cin >> n;
	S = new int[n];
	for(int i = 0;i < n;i++){
		cin >> S[i];
	}
	makeprogression();
	cout << pattern.size() << endl;
	while(true){
		cout << patterncopy.top();
		patterncopy.pop();
		if(!patterncopy.empty()){
			cout << " ";
		}else{
			cout << "" << endl;
			break;
		}
	}
	while(!pattern.empty()){
		insertsort(pattern.top());
		pattern.pop();
	}
	cout << cnt << endl;
	for(int j = 0;j < n;j++){
		cout << S[j] << endl;
	}
	return 0;
}