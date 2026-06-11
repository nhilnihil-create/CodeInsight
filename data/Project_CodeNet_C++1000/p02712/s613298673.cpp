#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    ll n;
    cin >> n;
    ll sum = 0;
    for (int i=1; i<=n; i++){
        if (i % 3 == 0 || i % 5 == 0){continue;}
        else {sum += i;}
    }
    cout << sum << endl;
    return 0;
}
