#include <bits/stdc++.h>
#define ll long long
#define ar array
#define nl '\n'
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 2*1e5;

int arr[N];

int main(){
    AC
    int n;
    cin>>n;
    int sum = 0;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        if(i%2==0)
            sum^=(arr[i]^arr[i-1]);
    }

    for(int i=1; i<=n; i++){
        cout<<(sum^arr[i])<<nl;
    }
}
