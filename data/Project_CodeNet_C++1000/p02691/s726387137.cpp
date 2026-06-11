#include<bits/stdc++.h>
using namespace std;
int main(){
        int n; cin>>n; int h[n+1]; for(int i=1;i<=n;i++) cin>>h[i];
        long long cnt=0;
        unordered_map<long long,int> mp;
        for(int i=1;i<=n;i++){
                int val=i-h[i];
                cnt+=mp[val];
                mp[i+h[i]]++;
        }
        cout<<cnt<<endl;
}

