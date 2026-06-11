#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,r;
    cin >> n >> r;
    int count = 0;
    while(n){
        n/=r;
        count++;
    }
    cout << count << endl;
}
