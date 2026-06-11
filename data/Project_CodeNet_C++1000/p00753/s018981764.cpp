#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(){
	int n;
	int p;
	int count;
	vector<int> v(300000,1);

	while(1){
		cin >> n;
		if(n == 0){
			break;
		}
		count = 0;
		for(int i = 0; i <= 2*n; i++){
			v[i] = 1;
			//cout << " testcase1 " << endl;
		}
		v[0] = 0;
		v[1] = 0;

		for(int i = 0; i <= 2*n;i++){	

			if(v[i] == 1){
				for(int j = 2*i; j <= 2*n; j+= i){
					v[j] = 0;
					//cout << " testcase 4" << endl;
				}
			}
			//cout << " testcase2 " << endl;
		}

		for(int i = n+1 ; i <= 2*n ; i++){
			if(v[i] == 1){
				count++;
			}
			//cout << " testcase3 " << endl;
		}
		cout << count << endl;

	}
}



		

 