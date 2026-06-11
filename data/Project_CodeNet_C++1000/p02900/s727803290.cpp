#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll,int>> pfact(ll n){
    vector<pair<ll,int>> fs = {};

    if(n<=1) return fs;

    for(ll i=2;i*i<=n;i++){
        int tmp = 0;
        while(n%i==0){
            n /= i;
            tmp++;
        }
        if(tmp>0) fs.push_back(make_pair(i,tmp));
    }
    if(n!=1) fs.push_back(make_pair(n,1));
    return fs;
}

ll gcd(ll a, ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

int main(void){
    ll a,b;
    cin >> a >> b;

    ll g = gcd(a,b);

    vector<pair<ll,int>> plist = pfact(g);
    cout << (int)plist.size()+1 << endl;
    return 0;
}