#include<bits/stdc++.h>

using namespace std;

#define lli long long int
#define pb  push_back
#define mp  make_pair

vector <lli> vv;

int main(){
    lli n, k, m;
    cin >> n >> k;

    n = n%k;

    if(n-k > -n){
        n = n-k;
        cout << abs(n);
    }
    else cout << n;
}
