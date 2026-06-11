#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
using namespace std;
typedef vector<int> vi;

int main(){
    long long H, atk = 0;
    cin >> H;

    while(H > 0){
        H /= 2;
        atk++;
    }
    
    cout << (long long)pow(2, atk) - 1 << endl;
    
    return 0;
}