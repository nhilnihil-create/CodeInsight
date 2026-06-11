#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;


int main(){
    ll n; set<string>a; string x;
    cin>>n;
    while(n--)
    {
        cin>>x; a.insert(x);
    }
    cout<<a.size();
    return 0;
}
