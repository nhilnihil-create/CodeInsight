#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <utility>
#include <string>

#define REP(i,n) for(int i = 0; i < n; i++)

typedef unsigned long ul;

using namespace std;

int main(){
	int n,count;
	while(cin >> n){
		REP(a, 10){
			REP(b, 10){
				REP(c, 10){
					REP(d, 10){
						if(a+b+c+d == n)
							count++;
					}
				}
			}
		}
		cout << count << endl;
		count = 0;
	}
}