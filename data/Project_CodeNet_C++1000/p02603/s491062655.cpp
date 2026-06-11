#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define  ll long long
int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    ll arr[n];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    ll cur=arr[0],x=0;
    vector<ll>v;
    for (int j = 1; j < n; ++j) {
        if(!x){
            if(arr[j]>arr[j-1])
                v.push_back(cur),cur=arr[j],x=1;
            else
                cur=min(cur,arr[j]);
        }
        else{
            if(arr[j]<arr[j-1])
                v.push_back(cur),cur=arr[j],x=0;
            else
                cur=max(cur,arr[j]);
        }
    }
    v.push_back(cur);
    long long res=1000,mx=1000,st=0;
    for (int k = 0; k < v.size(); ++k) {
        if(k%2==0){
            st=res/v[k];
            res%=v[k];
        }
        else{
            res+=st*v[k];
            st=0;
            mx=max(res,mx);
        }
    }
    cout<<mx<<endl;
    return 0;
}