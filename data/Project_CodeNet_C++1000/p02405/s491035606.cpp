#include<iostream>

using namespace std;

int main() {
	int i, j, W, H;
	while (cin >> H >> W, H || W){
		for (i = 1; i <= H; i++){
			for (j = 1; j <= W; j++){
			    if(i % 2 == 1){
                                     if(j % 2 == 1)
                                         cout << "#";
                                     else
                                         cout << ".";
                                 }            
                                 if(i % 2 == 0){
                                     if(j % 2 == 1)
                                          cout << ".";
                                     else
                                          cout << "#";
                                 }  
			}
			cout << endl;
		}
          cout << endl;
	}
}