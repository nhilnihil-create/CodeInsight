#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

double calcAverage(vector<double> S)
{
    double Sum = 0;
    for(int i = 0; i < S.size(); ++i){
        Sum += S[i];
    }
    return Sum / S.size();
}
double calcStandardDeviation(vector<double> S)
{
    double m = calcAverage(S);
    
    double aa = 0;
    for(int i = 0; i < S.size(); ++i){
        aa += pow(S[i] - m, 2);
    }
    return sqrt(aa/S.size());
}

int main()
{
    
    while(true){
        int n;
        cin >> n;
        if(n == 0){
            break;
        }
        vector<double> S(n);
        for(int i = 0; i < n; ++i){
            cin >> S[i];
        }
        cout << fixed << setprecision(4);
        cout << calcStandardDeviation(S) << endl;
    }
    return 0;
}