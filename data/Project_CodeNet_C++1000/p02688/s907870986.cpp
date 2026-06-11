#include <bits/stdc++.h>
#define ll long long
#define ar array
#define nl '\n'
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 2*1e5;

int hasSnack[105];

int main(){
    AC
    int n, k;
    cin>>n>>k;
    for(int i=0; i<k; i++){
        int d;
        cin>>d;
        for(int j=0; j<d; j++){
            int x;
            cin>>x;
            hasSnack[--x] = 1;
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        if(!hasSnack[i])
            ans++;
    }
    cout<<ans<<endl;
}