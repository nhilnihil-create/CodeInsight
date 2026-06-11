#include<bits/stdc++.h>
#include<vector>
#define inf 1000000
#define ll unsigned long long 
#define boostUP ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fsr(i,n) for(ll i=0;i<n;i++)
#define fcr(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define sz(arr) sizeof(arr)/sizeof(arr[0])

using namespace std;

int main(){
    int n, sum = 0; cin >> n;

    vector<int>arr(n,0);
    fsr(i,n) cin >> arr[i];

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            sum += (arr[i] * arr[j]);
        }
    }

    cout << sum << endl;
}


