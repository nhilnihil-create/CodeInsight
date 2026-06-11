#include <iostream>
using namespace std;
int main(void){
 
int m,d,sum = 0;
cin >> m >> d;

for (int i = 1; i <= m; i++){
    for (int j = 2; j <= d / 10; j++){
        for (int k = 2; k <= 9; k++){
             if(j * 10 + k > d){
              continue;
            }
            if (i == j * k){
                sum++;
            }
        }
    }
}

cout << sum << endl;
 
 return 0; 
}
