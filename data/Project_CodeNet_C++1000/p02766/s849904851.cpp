#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    int i = 0;
    int d = 0;
    while (pow(K,i) <= N){ 
        //割れるまで桁を増やす
        // このような条件式は"/"を含めず、割り算も積の形に直して書くべき
        i += 1;
    }
    cout << i << endl;
}