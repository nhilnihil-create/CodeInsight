#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
    ll N,K;
    cin >> N >> K;
    
    
    int count=0;
    while(N!=0){
        count++;
        N/=K;
    }
    
    cout << count << endl;
}
