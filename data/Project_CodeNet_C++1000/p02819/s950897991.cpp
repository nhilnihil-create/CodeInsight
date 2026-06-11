#include<bits/stdc++.h>
using namespace std;
bool is_prime(int x){
    for(int i = 2; i*i <= x; i++){
        if(x % i == 0) return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin >> x;

    while(!is_prime(x)) x++;
    cout << x << "\n";
}