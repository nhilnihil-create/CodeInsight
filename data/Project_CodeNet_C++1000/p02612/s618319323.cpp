#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,a,n;
    cin >> N;
    if(N%1000==0){
        cout << 0 << endl;
    }else{
        a = N / 1000;
        n = (a + 1) * 1000 - N;
        cout << n << endl;
    }
    return 0;
}