#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 10000;

int main(){
    int k,n;
    cin>>k>>n;
    vector<int> arr(n+1);

    for(int i = 0; i < n; i++) cin>>arr[i];
    int res = INT_MAX;
    arr[n] = k+arr[0];
    for(int i = 0; i < n; i++){
        res = min(res, k - (arr[i+1]-arr[i]));
    }
    cout<<res;
}

