#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i)
        cin >> a[i];
    
    sort(a.begin(), a.end());

    double x = (double)(a[0]+a[1])/2;
    for(int i=2; i<n; ++i){
        x = (x+a[i])/2;
    }

    cout << x;
}
