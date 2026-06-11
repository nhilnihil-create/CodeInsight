#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void boost(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    boost();
    string s1,s2;
    cin >> s1 >> s2;
    
    ll n=s1.length(),m=s2.length();
    ll i,j;
    vector<ll>v;
    for(i=0;i<=n-m;i++){
        ll count=0,k=0;
        for(j=i;j<i+m;j++){
            if(s1[j]!=s2[k])
            count++;
            k++;
        }
        //cout << j << endl;
        //cout << s1[i] << endl;
        v.push_back(count);
    }
    sort(v.begin(),v.end());
    cout << v[0] << endl;
}