#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;

    long long longest=0;
    long long k,n;
    cin>>k>>n;

    vector<long long> arr;

    for(int i=0;i<n;i++) {
        long long num;
        cin>>num;
        arr.push_back(num);
    }

    for(int i=1;i<n;i++) {
        longest=max(longest,arr[i]-arr[i-1]);
    }

    longest=max(longest, arr[0]-(0-(k-arr[n-1])));

    cout<<k-longest<<endl;



}


