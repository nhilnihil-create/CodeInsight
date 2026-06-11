#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int ans = 0;
    if(n!=1){
        ans += n*(n-1)/2;
    }
    if(m!=1){
        ans += m*(m-1)/2;
    }

    cout << ans << endl;
}