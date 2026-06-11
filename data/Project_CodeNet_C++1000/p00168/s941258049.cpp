#define REP(i,n) for (int i=0;i<(n);i++)
#include <iostream>
#include <cmath>
using namespace std;

int main(){
        int n=0;
        while(cin>>n&&n>0){
                double a[n+1];
                REP(i,n+1){
                        switch(i){
                        case 0:
                                a[i] = 1;
                                break;
                        case 1:
                                a[i] = a[i-1];
                                break;
                        case 2:
                                a[i] = a[i-1] + a[i-2];
                                break;
                        default:
                                a[i] = a[i-1] + a[i-2] + a[i-3];
                                break;
                        }
                }
                cout << ceil(a[n] / 10 / 365) << endl;
        }
}