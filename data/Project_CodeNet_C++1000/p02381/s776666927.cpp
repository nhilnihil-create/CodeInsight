#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;
double PI = acos(-1);

int main(){
    int n;
    double sum;
    double ave;
    while(cin >> n){
        if(n==0)break;
        double s[n];
        sum = 0;
        for(int i=0;i<n;i++){
            cin >> s[i];
            sum += s[i];
        }
        ave = sum / n;
        double alpha=0;
        for(int i=0;i<n;i++) alpha += pow(s[i] - ave, 2);
        cout << setprecision(10) << sqrt(alpha / n) << endl;
        
    }
    return 0;
}
