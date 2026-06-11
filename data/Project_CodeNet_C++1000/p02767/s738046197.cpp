#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> X(N);
    for(int i=0; i<N; i++) cin >> X.at(i);
    int Xmax = 0, Xmin = 101;
    for(int i=0; i<N; i++){
        if(X.at(i) < Xmin) Xmin = X.at(i);
        if(X.at(i) > Xmax) Xmax = X.at(i);
    }
    int min = 10000000;
    for(int i=Xmin; i<=Xmax; i++){
        int sum = 0;
        for(int j=0; j<N; j++) sum += pow((X.at(j) - i), 2);
        if(sum < min) min = sum;
    }
    cout << min << endl;
}