#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    int n; cin>> n;
    vector<int> a(n), a2(n);
    forin(a);
    a2=a;
    sort(a2.begin(), a2.end(), greater<int>());
    rep(i, n){
        if(a[i] == a2[0]){
            cout<< a2[1] << endl;
        }else{
            cout<< a2[0] << endl;
        }
    }
}