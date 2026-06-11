#include <bits/stdc++.h>
#define ENDL '\n'
#define io ios_base::sync_with_stdio(false);cin.tie(0);
#define sayY cout<<"YES"<<ENDL;
#define sayN cout<<"NO"<<ENDL;
#define sayy cout<<"Yes"<<ENDL;
#define sayn cout<<"No"<<ENDL;

typedef long long ll;
using namespace std;

int main(){
    io

    int n;
    cin >> n;

    vector<int> v(n);
    for(int i(0); i<n; i++){
        cin >> v[i];
    }

    for(int i(n-2); i>=0; i--){
        if(v[i] <= v[i+1]) continue;
        if(v[i]-v[i+1] == 1) v[i]--;
        else{
            sayn
            return 0;
        }
    }
    sayy

    return 0;
}