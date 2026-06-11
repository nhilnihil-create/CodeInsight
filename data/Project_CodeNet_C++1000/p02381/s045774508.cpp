#include "bits/stdc++.h"
using namespace std;
int main(){
    int n,i;
    double S,a;;
    while(true){
        cin >> n;
        if(n==0)break;
        vector<int> A(n);
        S=0;
        for(i=0;i<n;i++){
            cin >> A.at(i);
            S += A.at(i);
        }
        S /= n;
        a=0;
        for(i=0;i<n;i++){
            a += (A.at(i)-S)*(A.at(i)-S);
        }
        a /=n;
        printf("%.4lf\n",sqrt(a));
    }
    return 0;
}
