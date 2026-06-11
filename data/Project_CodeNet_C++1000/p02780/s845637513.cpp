#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int n, k;

    cin>>n>>k;

    vector<ll> p(n);
    vector<ll> s(n, 0);

    for(int i=0; i<n; i++){
        int p_tmp;
        cin>>p_tmp;
        p[i] = p_tmp+1;

        if(i>0){
            s[i] = s[i-1] + p[i];
        }else{
            s[i] = p[i];
        }
    }

    ll ans =s[k-1];
    for(int i=0; i<n-k; i++){
        ans = max(ans, s[i+k]-s[i]);
    }

    cout<< fixed << setprecision(10) <<(double)ans/2.0 <<endl;
    return 0;
}