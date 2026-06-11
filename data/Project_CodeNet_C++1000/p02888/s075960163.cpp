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
    int n, count = 0;
    cin >> n;
    vector<int>v (n,0);
    fsr(i, n) cin >> v[i];

    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++)
        for(int j = i+1; j<n; j++)
            for(int k = j+1; k<n; k++)
                count += v[i]+v[j] > v[k];
                    
    cout << count << endl;
}


