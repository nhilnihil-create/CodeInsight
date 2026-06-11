#include <bits/stdc++.h>
#define ENDL '\n'
#define io ios_base::sync_with_stdio(false);cin.tie(0);
#define sayy cout<<"Yes"<<ENDL;
#define sayn cout<<"No"<<ENDL;
#define sayY cout<<"YES"<<ENDL;
#define sayN cout<<"NO"<<ENDL;

typedef long long ll;
using namespace std;

int main(){
    io

    int n,l;
    cin >> n >> l;

    vector<int> v(n);
    int minval = INT_MAX, index;
    for(int i(0); i<n; i++){
        int x = l + (i+1) - 1;
        if(abs(x) < minval){
            minval = abs(x); index = i;
        }
        v[i] = x;
    }

    int ans(0);
    for(int i(0); i<n; i++){
        if(i == index) continue;
        ans += v[i];
    }
    cout << ans << ENDL;
    
    return 0;
}