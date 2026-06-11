#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long

int main(){
    int k, n;
    cin >> k >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i)
        cin >> a[i];

    vector<int> seg;
    for(int i=1; i<n; ++i){
        seg.push_back(a[i]-a[i-1]);
    }
    seg.push_back(k-a[n-1] + a[0]);


    int lg = *max_element(seg.begin(), seg.end());
    cout << k - lg;
    return 0;
}