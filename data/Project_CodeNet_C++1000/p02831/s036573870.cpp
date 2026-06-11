#include <bits/stdc++.h>
using namespace std;

#define ENDL '\n'
#define io ios_base::sync_with_stdio(false);cin.tie(0);
#define sayy cout<<"YES"<<ENDL;
#define sayn cout<<"NO"<<ENDL;

int gcd(int a, int b){
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

int main(){
    io

    long long int a, b;
    cin >> a >> b;

    cout << a*b / gcd(a,b) << ENDL;

    return 0;
}