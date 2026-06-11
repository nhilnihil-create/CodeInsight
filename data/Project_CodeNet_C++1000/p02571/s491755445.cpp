// Code by : h_mm 

#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ull unsigned long long
#define ll long long
#define test ll t; cin>>t; while(t--)
using namespace std;

int main(void) {
    string s, t;
    cin>>s>>t;
    int ans = INT_MAX;
    for(int i=0; i<=s.length()-t.length(); i++) {
        int cost = 0;
        // cout<<i<<" "<<s[i]<<endl;
        for(int j=0; j<t.length(); j++) {
            // cout<<t[j]<<" "<<s[i+j]<<"      ";
            if(t[j] != s[j+i]) {
                cost++;
            }
        }
        // cout<<"cost is : "<<cost<<endl;
        if(cost<ans) {
            ans = cost;
        }
    }
    cout<<ans;
}