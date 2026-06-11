#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define ll long long
#define pii pair<int,int>


void test_case()
{
    ll k;
    cin>>k;
    queue<ll> q;
    for(ll i=1;i<=9;i++)
        q.push(i);
    ll v;
    while(k--) {
        v=q.front();
        q.pop();
        if(v%10!=0)
            q.push(10*v + v%10 - 1);
        q.push(10*v + v%10);
        if(v%10!=9)
            q.push(10*v + v%10 +1);
    }
    cout<<v;
}

int main()
{
    fastio
//    int t;
//    cin>>t;
//    while(t--)
    test_case();
}
