#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz 100005
#define all(x) x.begin(),x.end()
#define l_b lower_bound
#define u_b upper_bound
#define pb push_back
#define MOD 1000000007
void fastio(void);

int main(){
    fastio();
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ll n,la,lb,x=0;
    cin>>n;
    vector<ll> arr(n);
    for(la=0;la<n;la++){
        cin>>arr[la];
        x^=arr[la];
    }

    for(la=0;la<n;la++)
        cout<<(x^arr[la])<<' ';

    return 0;
}

void fastio(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}