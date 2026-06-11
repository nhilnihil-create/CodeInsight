#include <iostream>
#define FOR(i,k,n) for (int (i)=(k); (i)<(n); ++(i))
#define REP(i,n) FOR(i,0,n)
using namespace std;

int main(){
    int m,min,max,gap,gapmax,n;
    while(cin >> m >> min >> max && m != 0){
        int p[m];
        REP(i,m){
            cin >> p[i];
        }
        gapmax = 0;
        FOR(i,min,max+1){
            gap = p[i-1] - p[i];
            if(gap >= gapmax){
                gapmax = gap;
                n = i;
            }
        }
        cout << n << endl;
    }


}