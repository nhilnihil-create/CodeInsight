#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
    long long a,b,k;
    cin>>a>>b>>k;
    
    b = max( b- max(k-a, 0LL), 0LL);
    a = max(a-k, 0LL);
    cout << a <<" "<<b << endl;
    return 0;
}