#include<bits/stdc++.h>
#include<vector>
#define ll long long
#define boostUP ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define fsr(i,n) for(ll i=0;i<n;i++)
#define fcr(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define sz(arr) sizeof(arr)/sizeof(arr[0])

using namespace std;

int main(){
    ll n,k;
    cin >> n >> k;
    ll arr[n];
    fsr(i,n) cin >> arr[i];
    ll count = 0, sum = 0;
    sort(arr,arr+n);
    if(n-k <= 0){
        count = 0;
    }
    else{
        for(int i=0; i<n-k; i++){
            sum += arr[i];
        }
        count = sum;
    }
    cout << count << endl;
}



 







 