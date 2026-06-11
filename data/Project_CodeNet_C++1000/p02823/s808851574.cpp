/************************************
/ AUTHOR : YATHARTH GOSWAMI         /  
/ ALIAS : hacker_yg                 /
/ INSTITUTE : IIT Kanpur            /
************************************/
//          TEMPLATE                //

#include <bits/stdc++.h>

#define ll long long
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n, a, b;
    cin >> n >> a >> b;
    if ((a+b)%2 == 0) {
        cout << (b-a)/2 << endl;
    }
    else {
        cout << min(a-1, n-b) + 1 + (b-a-1)/2 << endl;
    }
    return 0;
}


