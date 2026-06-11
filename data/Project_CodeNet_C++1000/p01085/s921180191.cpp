#include <iostream>
using namespace std;
int main(void){
    while(true){
        int m, Nmax, Nmin;
        cin >> m >> Nmin >> Nmax;
        if(m == 0){
            break;
        }
        int P[m];
        for(int i = 0; i < m; i++){
            cin >> P[i];
        }
        int maxGap = 0;
        int ret = 0;
        for(int i = Nmin - 1; i < Nmax; i++){
            if(P[i] - P[i + 1] >= maxGap){
                maxGap = P[i] - P[i + 1];
                ret = i + 1;
            }
        }
        cout << ret << endl;
    }
}