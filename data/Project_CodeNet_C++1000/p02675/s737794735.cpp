#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fi first
#define se second
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(a) cout << #a << " = " << a << " ";
#define endl "\n"
#define MOD (int) 1e9+7
#define inf (int) (1e18)

void solve(){
    int n;
    cin>>n;
    n=n%10;
    if(n==2 || n==4 || n==5 || n==7 || n==9)
       cout<<"hon\n";
    else if(n==0 || n==1 || n==6 || n==8)
        cout<<"pon\n";
    else 
        cout<<"bon\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t=1;
    // cin >> t;
    for(long int tt=1;tt<=t;tt++){
        solve();
    }
    return 0;
}