#include<bits/stdc++.h>
using namespace std;

int func(int a, int b){
    int res = 0;
    while(a > 0){
        a /= b;
        res++;
    }
    return res;
}

int main(){
    int N, K;
    cin >> N >> K;
    cout << func(N, K) << endl;
    return 0;
}