#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cmath>

#define rep(x,to) for(int x=0;x<to;x++)
#define rep2(x,from,to) for(x=from;x<to;x++)

using namespace std;


int main(void){
int aa[4], bb[4];
int ht, bl, j;

	while(cin >> aa[0]){
		rep2(j,1,4) cin >> aa[j];
		rep(i,4) cin >> bb[i];
		ht = 0; bl = 0;
		rep(i,4) rep(j,4) {
			if(aa[i] == bb[j]){
				if(i==j) ht++;
				else     bl++;
			}
		}	
		cout << ht << " " << bl << endl;
	}
	
	return 0;
}