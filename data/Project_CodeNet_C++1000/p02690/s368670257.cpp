#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define ll long long
#define pii pair<int,int>

void test_case()
{
    ll x;
    cin >> x;
    for(ll a=-118; a<= 119; a++) {
        for(ll b=-119; b<=118; b++) {
            if((a*a*a*a*a - b*b*b*b*b)==x) {
                cout<<a<<" "<<b;
                return;
            }
        }
    }
}


int main()
{
    fastio
//    int t;
//    cin>>t;
//    while(t--)
    test_case();
    return 0;
}
