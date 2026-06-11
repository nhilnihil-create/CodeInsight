#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int X = 0;
    double cnt = 0;
    while(X < N) {
        double A;
        cin >> A;
        cnt+=1.0/A;
        X++;
    }
    cout << fixed << setprecision(10) << 1.0/cnt << endl;
}
