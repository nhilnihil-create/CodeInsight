#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    ll n, k;
    cin >> n >> k; /// 2 2
    if (k > n){
            if (k >= 2 * n){cout << n << endl;}
            else {cout << abs (n - k) << endl;}
    }
    else {
        if (n % k == 0){
            cout << "0" << endl;
        }
        else {
            ll mul = (n / k) * k;
            ll temp = (n - mul);
            ll temp1 = abs (temp - k);
            cout << min (temp,temp1) << endl;
        }
    }

    return 0;
}
