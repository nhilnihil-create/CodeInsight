#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

int main(){
    cin >> n;
    if(n==0){
        cout << 0 << endl;
        return 0;
    }
    if(n%2==1){
        cout << 0 << endl;
        return 0;
    }
    ll count=0;
    ll memo=10;
    while(n>=memo){
        count+=n/memo;
        memo*=5;
    }
    cout << count << endl;
    return 0;
}  
