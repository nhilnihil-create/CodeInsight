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
    ll x;
    cin >> x;
//    ll ans = 0;
    if(360 % x == 0){
        //ans = 360 /x;
        cout << 360/x << endl;
        return 0;
    }else{
        reps(i,1,180){
            if((360*i) % x== 0)
            {
                cout << 360*i/x << endl;
                return 0;
            }
        }
    }

    return 0;
}