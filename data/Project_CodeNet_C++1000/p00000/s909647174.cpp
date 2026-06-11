#include <bits/stdc++.h>
#include <vector>
using namespace std;
int x, y;
int main(){
	for(int x = 1; x <= 9; x++){
		for(int y = 1; y <= 9; y++){
			cout << x << "x" << y << "=" << x*y <<"\n";
		}
	}
	return 0;
}