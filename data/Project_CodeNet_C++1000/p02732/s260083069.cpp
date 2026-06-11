#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'

int main(){
    int n;
    cin >> n;
    map<int, int> m;
    vector<int> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
        m[a[i]]++;
    }

    ull tp = 0;
    for(auto x:m){
        if(x.second)
            tp += 1.0*x.second*(x.second-1)/2;
    }

    for(int i=0; i<n; ++i){
        ull p = 1.0*(m[a[i]])*(m[a[i]]-1)/2;
        ull nw = 1.0*(m[a[i]]-1)*(m[a[i]]-2)/2;
        cout << tp - p + nw << endl;
    }
}
