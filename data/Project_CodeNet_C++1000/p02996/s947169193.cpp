#include <bits/stdc++.h>
using namespace std;
int main(){
    long n,t=0; cin >> n;
    vector<pair<long,long>> v(n);
    for(int i=0;i<n;i++){
        long a,b; cin >> a >> b;
        v[i] = make_pair(b,a);
    }
    bool B = true;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        long a,b; tie(b,a) = v[i];
        t += a;
        if(t > b){
            cout << "No" << endl;
            B = false;
            break;
        }
    }
    if(B)cout << "Yes" << endl;
}