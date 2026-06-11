#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;

    int n,x,y;
    cin>>n>>x>>y;

    vector<int> arr(n+1);

    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            arr[min({j-i,abs(x-i)+1+abs(j-y)})]++;
        }
    }
    
    for(int i=1;i<n;i++) {
        cout<<arr[i]<<endl;
    }
}


