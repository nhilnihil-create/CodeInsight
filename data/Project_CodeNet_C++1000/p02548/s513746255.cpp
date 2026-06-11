#include<bits/stdc++.h>
using namespace std;
using lint = long int;

int N;
lint res = 0;

int main(){
    cin >> N;
    
    for(int i = 1; i <= N; i++){
        if(N % i == 0) res += N/i-1;  //C0阻止
        else res += N/i;
    }

    cout << res << endl;
    return 0;
}
