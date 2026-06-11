#include<bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
using namespace std;

int main(){
    ll x;
    cin >> x;
    if(x%1000 == 0){
        cout << 0 << endl;
    }
    
    else{
        cout << (1000 - x%1000) << endl;
    }
    return 0;
}