#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
#define rep(i,n) for (int i=0;i<(n);i++)

using namespace std;

vector<int> g[200005];

int main() {
	int a;
    string s;
	cin >> a >> s;
  
	if(a>=3200){
       cout << s << endl;
    }
    else{
       cout << "red" << endl;
    }
	return 0;
}
