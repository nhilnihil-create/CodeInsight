#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    int n; cin>> n;
    vector<ll> h(n);
    forin(h);
    for(int i=1; i<n; i++){
        if(h[i-1] > h[i]){
            cout<< "No" << endl;
            return 0;
        }else{
            if(h[i] != h[i-1]) h[i]--;
        }
    }
    cout << "Yes" << endl;
}