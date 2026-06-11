#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    double t1,t2;
    double a1,a2;
    double b1,b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    ll ans = 0;
    if((a1 > b1 && a2 >= b2) || (b1 > a1 && b2 >= a2)){
        cout << ans << endl;
        return 0;
    }else if(t1*a1 + t2*a2 == t1*b1 + t2*b2){
        cout << "infinity" << endl;
        return 0;
    }else if((a1 > b1 && t1*a1 + t2*a2 > t1*b1 + t2*b2) || (a1 < b1 && t1*a1 + t2*a2 < t1*b1 + t2*b2)){
        cout << ans << endl;
        return 0;
    }else{
        ans += 1;
        if(b1 > a1){
            swap(a1,b1);    swap(a2,b2);
        }
        ll dif = (t2*b2 + t1*b1 - t2*a2 - t1*a1);
        ll dif2 = t1*(a1 - b1);
        if(dif2%dif == 0){
            ans += (dif2/dif-1)*2;
            ans += 1;
        }else{
            ans += (dif2/dif-1)*2;
            ans += 2;
        }
    }
    cout << ans << endl;
    return 0;
}