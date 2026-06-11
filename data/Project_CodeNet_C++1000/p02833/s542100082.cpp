#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define mm(arr) memset(arr, 0, sizeof(arr))
#define scanArray(a,n) for(int i = 0; i < n; i++){cin >> a[i];}
#define pb push_back
#define PI 3.141592653589793
#define MOD 1000000007

using namespace std;

int main(){
    FAST
    ll cnt =0;
    ll n; cin >> n;
    if(n<10){
        cout << "0" << endl;
        return 0;
    }
    ll a=n;
    if(n%2!=0){
        cout << "0" << endl;
        return 0;
    }

    else{
        ll ans=0,sum=0,i=5;
        while(n/i>=1){
            ans=n/(i*2);
            sum+=ans;
            ans=0;
            i*=5;
        }
        cout << sum << endl;
    }




    return 0;
}
