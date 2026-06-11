#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int X = 100*N / 108, flag = 0;
    while(true){
        if(108*X/100 == N){
            cout << X << endl;
            break;
        }
        else if(108*X/100 > N){
            cout << ":(" << endl;
            break;
        }
        else ++X;
    }
    return 0;
}