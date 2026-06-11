#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
 
int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    map<string,int> mp;
    int maxi=0;
    for(int i=0;i<n;i++){
        cin >> s[i];
        mp[s[i]]++;
        maxi=max(maxi,mp[s[i]]);
    }
    vector<string> ans;
    for(auto x:mp){
        if(x.second==maxi){
            ans.push_back(x.first);
        }
    }
    sort(ans.begin(),ans.end());
    for(auto x:ans){
        cout << x << endl;
    }
    return 0;
}