#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    string s;
    cin>>s;

    ll x;
    cin>>x;

    bool rev=false;
    for(int i=0;i<x;i++) {
        int t;
        cin>>t;

        if(t==2) {
            if(rev) {
                reverse(s.begin(),s.end());
                rev=!rev;
            }
            int pos;
            cin>>pos;

            string y;
            cin>>y;
            if(pos==1) {
                s.insert(0,y);
            }
            else {
                s.append(y);
            }
        }
        else {
            rev=!rev;
        }
    }
    if(rev) {
        reverse(s.begin(),s.end());
    }
    cout<<s<<endl;
}


