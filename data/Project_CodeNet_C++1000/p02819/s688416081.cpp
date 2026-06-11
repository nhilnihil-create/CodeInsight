#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
bool check_prime (int x)
{
    for (int i=2; i*i<=x; i++){
        if (x % i == 0){return false;}

}
return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    ll n;
    cin >> n; /// 20
    ll i = n; /// 20
    ll num;
    while (1){
        if (check_prime(i)){
           num = i; break;
        }
        i++;
    }
    cout << num << endl;
}
