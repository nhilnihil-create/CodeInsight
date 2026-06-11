#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    int n,k;
    cin>>n>>k;
    vector<int> snukes(n);
    for(int i=0;i<k;i++) {
        int num;
        cin>>num;
        for(int j=0;j<num;j++) {
            int snack;
            cin>>snack;
            snukes[snack-1]++;
        }
    }

    int ans=0;
    for(int i=0;i<n;i++) {
        if(snukes[i]==0) {
            ans++;
        }
    }
    cout<<ans<<endl;
    
}


