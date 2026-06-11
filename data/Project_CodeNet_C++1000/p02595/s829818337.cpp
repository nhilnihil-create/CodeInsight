#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,d,a,b,ans=0;
    cin >> n >> d;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        if(d*d>=a*a+b*b)ans++;
    }
    cout << ans << endl;
    return 0;
}
