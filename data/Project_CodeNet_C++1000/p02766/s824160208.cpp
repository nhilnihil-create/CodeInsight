#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N, K;
    cin >> N >> K;


    int count = 0;
    while(N > 0){
         N = N / K;
         count++;
    }

    cout << count << endl;
}