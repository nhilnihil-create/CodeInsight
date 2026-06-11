#define _USE_MATH_DEFINES 
#include <cmath>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#define rep(i,n) for(int i=0;i<n;i++)
#define And &&
#define Or ||
#define Lb cout<<endl
using namespace std;

int main() {
	int H, W;
	while (true) {
		cin >> H >> W;
		if (H == 0 And W == 0)break;
		rep(i, H) {
			rep(j, W) {
				if ((i + j) % 2 == 0)cout << "#";
				else cout << ".";
			}
			Lb;
		}
		Lb;
	}
}