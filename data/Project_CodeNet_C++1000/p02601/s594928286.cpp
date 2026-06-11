#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define sort_1(v) sort(v.begin(),v.end())
#define sort_2(v) sort(v.begin(),v.end(),greater<ll>())
#define reverse(v) reverse(v.begin(),v.end())
typedef long long ll;
typedef long double la;
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int k;
    cin >> k;

    rep(i,0,k){
        if(a >= b){
            b *= 2;
            continue;
        }else{
            c *= 2;
            continue;
        }
    }

    if(a < b && b < c){
        cout << "Yes" << endl;
        return 0;
    }else{
        cout << "No" << endl;
        return 0;
    }
}