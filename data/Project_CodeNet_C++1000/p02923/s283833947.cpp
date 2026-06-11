#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i){
        cin >> a[i];
    }

    int ans=0;
    for(int i=0; i<n; ++i){
        int j=0;
        while(j+i+1<n && a[i+j]>=a[i+j+1]){
            ++j;
        }
        i+=j;
        ans = max(ans, j);
    }
    cout << ans;
}
