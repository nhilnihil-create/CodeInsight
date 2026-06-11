#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> point(n) ;
    rep(i, n) point[i] = 0;

    vector<int> a(q);
    for(int i=0; i<q; i++){
        cin >> a[i];
        point[a[i]-1]++;
    }
    for(int i=0; i<n; i++){
        if(point[i]>q-k)
            cout << "Yes" << endl;
        else
        {
            cout << "No" << endl;
        }   
    }
    return 0;
}