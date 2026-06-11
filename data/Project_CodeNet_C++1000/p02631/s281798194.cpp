#include <bits/stdc++.h>
#include <string>

using namespace std;

int gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }
#define rep(i,n) for(int i = 0;i<n;i++)

int int_xor(int a,int b){
    int x = max(a,b);
    int y = min(a,b);
    int z = 0;
    int t = 1;
    while(x>0){
        z += ((x+y)%2)*t;
        y/=2;
        x/=2;
        t *= 2;
    }
    return z;
}

int main(){

    int N;cin >> N;
    vector<int> a(N);
    int sum = 0;
    rep(i,N){
        cin >> a[i];
        sum = int_xor(sum,a[i]);
    }
    rep(i,N)cout << int_xor(sum,a[i]) << endl;
    
    
    
    
    

}

