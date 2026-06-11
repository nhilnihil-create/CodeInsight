#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int a, long long int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    
    if (b == 0) return a;
    else return gcd(b, a % b);
}

long long int lcm(long long int a, long long int b) {
    return a / gcd(a,b) * b;// divide first to avoid overflow
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    set<int> a_set;
    for(int i=0; i<n; i++){
        cin >> a[i];
        a[i] /= 2;
        a_set.insert(a[i]);
    }

    int ans = 0;
    int x = a[0];
    for(int i=1; i<n; i++){
        x = gcd(x, a[i]);
    }

    long long int y = 1;
    for(int z : a_set){
        y = lcm(y,z);
        if(y > m){
            cout << 0 << endl;
            return 0;
        }
    }

    bool flag = true;
    long long int first = y;
    for(int i=0; i<n; i++){
        if((first / a[i]) % 2 == 0) flag = false;
    }
    
    if(flag == false) cout << 0 << endl;
    if(flag == true) cout << 1 + (m - (int)y) / (2*y) << endl;
    return 0;
}