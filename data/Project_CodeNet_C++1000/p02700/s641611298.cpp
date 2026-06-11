#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >>d;
    while(a>0 && c>0){
        c -= b;
        if(c<=0){
            cout << "Yes" << endl;
            return 0;
        }
        a -= d;
    }
    cout << "No" << endl; 
    return 0;
}


