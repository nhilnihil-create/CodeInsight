#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vll vector<ll>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ld x;
    cin >> x;
    
    ld y = x/3, vol = 0;
    vol = y*y*y;
    cout << fixed << setprecision(12) << vol << endl;
    return 0;
}