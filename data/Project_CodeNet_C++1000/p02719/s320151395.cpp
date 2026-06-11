#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    vector<long long> arr;

    long long n,k;
    cin>>n>>k;

    long long ans=abs(n-k);
    bool loop=false;
    while(loop==false) {
        if(find(arr.begin(),arr.end(),n)!=arr.end()) {
            loop=true;
        }
        if(n>k) {
            arr.push_back(n%k);
            n=n%k;
        }
        else{
            arr.push_back(abs(n-k));
            n=abs(n-k);
        }
         for(int i=0;i<arr.size();i++) {
         }
        ans=min(ans,n);
    }

    cout<<ans<<endl;

    
}


