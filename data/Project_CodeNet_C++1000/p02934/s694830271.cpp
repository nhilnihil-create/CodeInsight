#include <bits/stdc++.h>
using namespace std ;
int main(){
    int n;
    int c;
    cin >> n;
    double sum=0.0;
    for(int i=0;i<n;i++){
        cin >> c;
        sum+=1.0/c;
    }
    double R = 1/sum;
    cout << setprecision(16) << R << endl;
}