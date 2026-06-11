#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
    int i;
    double n,sum,s[1000]={},m,alpha;

    cout << fixed << setprecision(8);
    while(cin >> n){
        if(n == 0) break;
        for(i=0;i<n;i++){
            cin >> s[i];
            sum += s[i];
        }
        m = sum / n;
        sum = 0;
        for(i=0;i<n;i++) sum += pow(s[i] - m, 2);
        alpha = sqrt(sum / n);
        cout << alpha << endl;

        sum = 0;
        for(i=0;i<n;i++) s[i] = 0;
    }
}

