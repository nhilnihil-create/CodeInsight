#include <bits/stdc++.h>
#define ll long long 
#define P pair<ll, ll>
using namespace std;

int main(){
    int n; 
    cin >> n;
    vector<P>vec(n);
    for(int i=0;i<n;i++){
        ll a, b;
        cin >> a >> b;
        P p;
        p.first = b;
        p.second = a;
        vec[i] = p;
    }
    sort(vec.begin(), vec.end());

    ll t = 0;
    for(int i=0;i<n;i++){
        ll b = vec[i].first;
        ll a = vec[i].second;
        if(t+a <= b) t += a;
        else {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

}