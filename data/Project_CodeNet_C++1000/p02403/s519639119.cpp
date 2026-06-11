#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
using namespace std;
int main(){
	for (;;){
		int H, W;
		cin >> H >> W;
		if (H == 0 && W == 0){
          break;
		}
		
		for (int x = 0; x < H; x++){
			for (int y = 0; y < W; y++){
				cout << "#";
			}
			cout << "" << endl;
		}
		cout << "" << endl;
	}

	return 0;
}
