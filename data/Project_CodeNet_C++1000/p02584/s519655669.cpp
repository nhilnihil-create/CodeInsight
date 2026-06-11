#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

const int MAX = 100;

int main(){
    long long X,K,D;
    long long ans = 0;
    int sign = 0;

    cin >> X >> K >> D;

    X = abs(X);

    if(X > D){
        long long x = X / D;

        if(x < K){
            if((K - x) % 2)x++;
            ans = X - D * x;
        }else{
            ans = X - D * K;
        }
    }else{
        if(K % 2)ans = X - D;
        else ans = X;
    }

    cout << abs(ans) << endl;

    return 0;
}