#include <bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;
using G=vector<vector<int>>;

int main(){
    string s,t;
    cin >> s >> t;
    G st(26,vector<int>(0));
    vector<int> num(26,0);
    int n=s.size();
    rp(i,n){
        st[s[i]-'a'].push_back(i);
        num[s[i]-'a']++;
    }
    int m=t.size();
    int pos=-1;
    int strs=0;
    rp(i,m){
        int ch=t[i]-'a';
        if(num[ch]==0){
            cout << -1 << endl;
            return 0;
        }
        if(st[ch].back()<=pos){
            pos=st[ch][0];
            strs++;
            continue;
        }
        auto it=upper_bound(st[ch].begin(),st[ch].end(),pos);
        pos=*it;
    }
    cout << (ll)n*(ll)strs+(ll)pos+(ll)1 << endl;
    return 0; 
}