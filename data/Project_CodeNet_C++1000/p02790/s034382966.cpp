#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int a, b;
    cin >>a>>b;
    int min1 = min(a,b);
    int max1 = max(a, b);
    int ans=0;
    rep(i, max1){
        ans+=min1*pow(10, i);
    }
    cout << ans << endl;
}