#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int n, k;
    cin>>n>>k;
    vector<int> v(n);
    rep(i, n) cin>>v[i];
    vector<int> imo(n+1);
    /*いもす法*/
    rep(j, min(k, (int)log2(n)+100)){
        imo = vector<int>(n+1);
        rep(i, n){
            imo[max(0, i-v[i])]++;
            imo[min(i+(v[i]+1), n)]--;
        }
        int bef = 0;
        rep(i, n){
            bef+=imo[i];
            v[i] = bef;
        }
    }
    rep(i, n) cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}