#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    ll l,r;
    ll m = 2e9;
    cin >> l >> r;

    if(r-l >= 2500){
        cout << 0 << endl;
        return 0;
    }else{

        for(ll i = l; i < r+1;i++){
            for(ll j = i+1; j < r+1; j++){
                ll tmp = (i*j)%2019;
                m = min(m,tmp);
            }
        }

        // reps(i,l,r+1){
        //     reps(j,i+1,r+1){
        //         ll tmp = i*j;
        //         tmp %= 2019;
        //         m = min(m,tmp);
        //         //cout << i << " " << j << endl;
        //     }
        // }
    }

    cout << m << endl;
    return 0;
}
