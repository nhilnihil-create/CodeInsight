#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;

    ll n;
    cin>>n;

    vector<ll> count(n+1);
    vector<ll> arr;

    for(int i=0;i<n;i++) {
        ll num;
        cin>>num;

        count[num]++;
        arr.push_back(num);
    }

    ll total=0;

    for(int i=1;i<=n;i++) {
        if(count[i]!=0) {
            total+=(count[i]*(count[i]-1))/2;
        }
    }

    for(int i=0;i<n;i++) {
        cout<<total-count[arr[i]]+1<<endl;
    }


    
}
