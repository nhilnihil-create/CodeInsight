#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

int main(){

    ll n;
    cin >> n;
    string s[n];
    for(ll i=0;i<n;i++)cin >> s[i];

    sort(s,s+n);

    vector<string> v;

    ll m=1;
    ll c=1;
    string t=s[0];
    for(ll i=1;i<n;i++){
        if(t==s[i])c+=1;
        else{
            if(c>m){
                v.clear();
                v.push_back(t);
                m=c;
            }
            else if(c==m){
                v.push_back(t);
            }
            t=s[i];
            c=1;
        }
    }
    if(c>m){
        v.clear();
        v.push_back(s[n-1]);
        m=c;
    }
    else if(c==m){
        v.push_back(s[n-1]);
    }

    for(ll i=0;i<v.size();i++){
        for(ll j=0;j<v[i].size();j++)cout << v[i][j];
        cout << endl;
    }


}