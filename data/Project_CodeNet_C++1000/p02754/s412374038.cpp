#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;

int main(){
    long long int n, a, b;
    cin >> n >> a >> b;
    long long int ans = 0;
    ans += n/(a+b)*a;
    n = n%(a+b);
    if(n<=a){
        ans += n;
    }else{
        ans += a;
    }
    cout << ans << endl;
}