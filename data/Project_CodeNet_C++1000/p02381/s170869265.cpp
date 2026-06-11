#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;


int main()
{
    
    while(true){
        int n;
        cin >> n;
        if(n == 0){
            break;
        }
        vector<double> S(n);
        double Sum = 0;
        for(int i = 0; i < n; ++i){
            cin >> S[i];
            Sum += S[i];
        }
        double m = Sum / n;
        double aa = 0;
        for(int i = 0; i < n; ++i){
            aa += pow(S[i] - m, 2);
        }
        double a = sqrt(aa/n);
        cout << fixed << setprecision(4) << a << endl;
    }
    return 0;
}