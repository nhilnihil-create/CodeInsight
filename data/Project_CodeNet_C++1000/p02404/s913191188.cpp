#include<iostream>

using namespace std;

int main() {
	int i, j, W, H;
	while (cin >> H >> W, H || W){
		for (i = 1; i <= H; i++){
			for (j = 1; j <= W; j++){
			    if(i > 1 && i != H && j > 1 && j != W)
                                     cout << ".";
                                 else
                                     cout << "#";
			}
			cout << endl;
		}
          cout << endl;
	}
}