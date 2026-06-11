#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

int main(){
    int n;
    cin>>n;

    map<string,int> mp;
    rep(i,n){
        string s;
        cin>>s;
        sort(s.begin(),s.end());
        mp[s]++;
    }
    ll ans=0;
    for(auto p:mp){
        int s=p.second;
        ans+=(ll)s*(s-1)/2;
    }
    cout<<ans<<endl;

    return 0;
}

