#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)

int main() {
    ll N;
    cin >> N;
    map<ll,ll> mp;
    vector<ll> v;
    ll A[N];
    rep(i,N){
        cin >> A[i];
        if(mp.count(A[i])) mp[A[i]]++;
        else{
            v.push_back(A[i]);
            mp.emplace(A[i],1);
        }
    }
    sort(v.begin(),v.end());
    string out = "No";
    if(v.size()==1&&v[0]==0) out = "Yes";
    else if(N%3==0){
        if(v.size()==2&&v[0]==0&&mp[0]==N/3) out = "Yes";
        else if(v.size()==3&&(mp[v[0]]==mp[v[1]]&&mp[v[1]]==mp[v[2]])){
            if(((v[0]^v[1])^v[2])==0) out = "Yes";
        }
    }
    cout << out << endl;
    return 0;
}
