#include <bits/stdc++.h>
//#include <iostream>
// #include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> B(N-1);
    for (int i=0; i<N-1; ++i){
        cin >> B.at(i);
    }
    vector<int> A(N);
    A.at(0) = B.at(0);
    for(int i=1; i<N-1; ++i){
        if(B.at(i-1) <= B.at(i)){
            A.at(i) = B.at(i-1);
        }
        else{
            A.at(i) = B.at(i); 
        }
    }
    A.at(N-1) = B.at(N-2);

    int sum=0;
    for (int i=0; i<N; i++){
        sum += A.at(i);
    }
    cout << sum;
    return 0;
}
