#include <bits/stdc++.h>
using namespace std;

int main(void){
 
    int N;
    cin >> N;
    
    if(N %2 == 0){
        cout << (double)1 / 2 <<endl;
    }
    else{
        cout << (double)((N / 2) + 1) / N <<endl;
    }
}