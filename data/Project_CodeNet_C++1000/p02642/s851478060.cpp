#include <bits/stdc++.h>
#define ll long long
#define ar array
#define nl '\n'
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 1e6;

bool first_occ[N+5];
int arr[N+5];
int n;
int ans=0;


int main(){
    AC
    cin>>n;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        arr[a]++;
    }

    for(int i=1; i<=N; i++){
        if(arr[i]==0) continue;
        for(int j=i*2; j<=N; j+=i)
            arr[j]=0;
        if(arr[i]==1) ans++;
    }
    cout<<ans<<nl;
}