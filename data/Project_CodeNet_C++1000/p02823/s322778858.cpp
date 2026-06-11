#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main(){
    fastio;
    long long n,a,b;
    cin >> n >> a >> b;
    long long di = b-a;
    if(di%2==0){cout << di/2 <<"\n";}
    else{
        long long ans = (b-a-1)/2;
        cout << ans+min(a-1,n-b)+1 <<"\n";
    }
    return 0;
}
