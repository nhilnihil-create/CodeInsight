    #include <iostream>
    #define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #include <algorithm>
    #include <bits/stdc++.h>
    #define MOD 1000000007
    #define ll long long
    #define mm(arr) memset(arr, 1, sizeof(arr))
    #define scanArray(a,n) for(int i = 0; i < n; i++){cin >> a[i];}
    using namespace std;

    int main(){
        FAST
        ll n; cin >> n;
        ll a[n];
        mm(a);
        ll sum=0;
        for(ll i=1; i<n+1; i++){
            a[i] = i;
        }
        for(ll i=1; i<n+1; i++){
        if(i%3 != 0 && i%5 != 0 && a[i] %3 != 0 && a[i] % 5 !=0){
            sum+=a[i];

        }
        else{

            continue;
        }
        }
        cout << sum << endl;

        return 0;
    }
