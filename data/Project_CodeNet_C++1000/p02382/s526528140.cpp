#include <iostream>
#include <math.h>
#include <algorithm>
#include <iomanip>
using namespace std;
int main(void){
    // Your code here!
    int cnt;
    double ans1, ans2, ans3, an3Mugen;
    cin >> cnt;
    int x[cnt];
    int y[cnt];
    int wkDis[cnt];
    
    for(int i=0; i<cnt; i++){
        cin >> x[i];
    }
    
    for(int i=0; i<cnt; i++){
        cin >> y[i];
    }
    
    for(int i=0; i<cnt; i++){
        wkDis[i] = abs(x[i] - y[i]);
    }
    
    for(int i=0; i<4; i++){
        double Distance, sum;
        sum = 0;
        switch(i){
            case 0:
                for(int j=0; j<cnt; j++){
                    sum += wkDis[j];
                }
            break;
            case 1:
                for(int j=0; j<cnt; j++){
                    sum += pow(wkDis[j],2);
                }
                sum = pow(sum, 1.0/2);
            break;
            case 2:
                for(int j=0; j<cnt; j++){
                    sum += pow(wkDis[j],3);
                }
                sum = pow(sum, 1.0/3);
            break;
            case 3:
                for(int j=0; j<cnt; j++){
                    if(wkDis[j] >= sum) sum = wkDis[j];    
                }
            break;
        }
        cout << fixed << setprecision(6) << sum << endl;
    }
}

