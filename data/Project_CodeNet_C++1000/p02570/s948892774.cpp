// Code by : h_mm 

#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ull unsigned long long
#define ll long long
#define test ll t; cin>>t; while(t--)
using namespace std;

int main(void) {
    fast;
    float d, t, s;
    cin>>d>>t>>s;
    if((d/s) <= t) {
        cout<<"Yes";
    } else {
        cout<<"No";
    }
    return 0;
}