#include <bits/stdc++.h>
#define ll long long
#define ar array
#define nl '\n'
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 2*1e5;

int n, k;
vector<int> arr;

int main(){
    AC
    cin>>n>>k;
    arr.resize(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    sort(arr.begin(), arr.end());
    int ans = 0;
    for(int i=0; i<k; i++)
        ans+=arr[i];
    cout<<ans<<nl;

}