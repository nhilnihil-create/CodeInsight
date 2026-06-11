#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()

int main(){
    int n;
    cin >> n;
    vector<int> a(n), p(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }

    int d = a[0], cnt=1;
    for(int i=1; i<n; ++i){
        if(a[i] <= d){
            cnt++;
            d=a[i];
        }
    }
    cout << cnt;
}