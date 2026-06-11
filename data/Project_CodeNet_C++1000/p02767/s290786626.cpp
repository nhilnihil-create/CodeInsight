#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    vector<int> arr;
    int n;
    cin>>n;

    int mn=0, mx=0;
    for(int i=0;i<n;i++) {
        int num;
        cin>>num;
        arr.push_back(num);

        mn=min(mn,num);
        mx=max(mx,num);
    }

    int ans=numeric_limits<int>::max();
    for(int i=mn;i<=mx;i++) {
        int tmp=0;
        for(int j=0;j<n;j++) {
            tmp+=((pow(i-arr[j],2)));
        }
        ans=min(ans,tmp);
    }
    cout<<ans<<endl;


}


