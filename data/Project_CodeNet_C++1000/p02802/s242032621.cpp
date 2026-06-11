#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;

    ll n,m;
    cin>>n>>m;

    vector<int> c_arr(n+1);
    vector<int> w_arr(n+1);

    for(int i=0;i<m;i++) {
        int p;
        string s;
        cin>>p>>s;

        int c_ans=0;
        int w_ans=0;
        if(c_arr[p]!=1) {
            if(s=="WA") {
                w_arr[p]++;
            }
            else {
                c_arr[p]=1;
            }
        }
    }

    int c_ans=0;
    int w_ans=0;
    for(int i=1;i<=n;i++) {
        if(c_arr[i]==1) {
            c_ans++;
            w_ans+=w_arr[i];
        }
    }


    cout<<c_ans<<' '<<w_ans<<endl;
    
}


