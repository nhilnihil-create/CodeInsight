#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    unsigned long long res;
    
    if(N&1){
        res = N-1;
        res >>= 1;
        res *= N;
    }else{
        res = N;
        res >>= 1;
        res *= N-1;
    }
    
    cout << res << endl;
    
    return 0;
}
