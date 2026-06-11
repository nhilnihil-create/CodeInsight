#include<bits/stdc++.h> 
using namespace std;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    
    long long t;
    cin>>t;

    long long ans=1;
    
    vector<long long> arr;
    while(t--) {
        long long num;
        cin>>num;
        if(num==0) {
            cout<<0<<endl;
            return 0;
        }
        arr.push_back(num);
    }

    long long of=1e18;
    for(int i=0;i<arr.size();i++) {
        if(of/ans<arr[i]) {
            cout<<-1<<endl;
            return 0;
        }

        ans*=arr[i];
    }

    cout<<ans<<endl;

}


