#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

ll N, ans=0;

void yakusuu1(ll num) {
    for(int i=2;i*i<=num;i++) {
        if(num%i==0) {
            if(i==num/i) ans++;
            else ans += 2;
        }
    }
    if(num!=1) ans++;
    //cout << "OK1" << endl;
}

void yakusuu2(ll num) {
    for(int i=2;i*i<=num;i++) {
        int num1 = num;
        int flag=0;
        while(num1%i==0) {
            num1 /= i;
            flag=1;
            //cout << i << " : " << num1 << endl;
        }
        if(flag==1&&num1%i==1) ans++;
    }
    if(num!=1) ans++;
    //cout << "OK2" << endl;
}

signed main(){
    cin >> N;
    yakusuu1(N-1);
    yakusuu2(N);
    //cout << endl;
    cout << ans << endl;
    return 0;
}