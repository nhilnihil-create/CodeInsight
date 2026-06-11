#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int A,B,C,K;
    cin >> A >> B >> C >> K;
    int max;
    if(A >= K){
        max = K;
    }
    else if(A+B >= K){
        max = A;
    }
    else{
        max = A - (K - A - B);
    }
    cout << max << endl;
    return 0;
}