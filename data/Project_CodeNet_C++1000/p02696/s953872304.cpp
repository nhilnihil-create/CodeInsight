#include <bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;
typedef vector< vector<char> > vvc;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef long long ll;

int main(){
    ll a,b,n;
    cin >> a >> b >> n;
    ll ans;
    ll i;
    if(n<b){
        i=n;
        ans=a*i/b-a*(i/b);
    }else{
        i=b-1;
        ans=a*i/b-a*(i/b);
    }
    /*
    for(int i=1;i<=n;i++){
        ll temp=a*i/b-a*(i/b);
        cout << temp << endl;
        ans=max(ans,temp);
    }
    */
    cout << ans << endl;
    return 0;
}