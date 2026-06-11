#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    ll n,k,total;
    cin>>n>>k;

    total=0;

    vector<ll> arr;
    while(n--) {
        ll num;
        cin>>num;
        arr.push_back(num);
        total+=num;
    }

    sort(arr.begin(),arr.end(),greater<ll>());

    for(int i=0;i<arr.size();i++) {
        if(k>0) {
            total-=arr[i];
            k--;
        }
        else {
            break;
        }
    }

    cout<<total<<endl;



}


