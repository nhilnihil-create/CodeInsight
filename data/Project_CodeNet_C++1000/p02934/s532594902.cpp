#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    int N;
    cin >> N;
    
    double A;

    double sum = 0;
    
    for(int i = 0; i < N;i++){
        cin >> A;
        sum += 1/A;
    }
    cout <<setprecision(12)<< 1/sum <<endl;

}
