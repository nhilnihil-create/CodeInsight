#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    unsigned long long res = N;
  	res *= N - 1;
    res >>= 1;
    
    cout << res << endl;
    
    return 0;
}
