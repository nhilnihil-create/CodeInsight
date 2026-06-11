#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;

int main(){
    int n,r;
    cin >> n >> r;
    int ans = r;
    if(n < 10){
        ans += 100*(10-n);
    }
    cout << ans << endl;
}