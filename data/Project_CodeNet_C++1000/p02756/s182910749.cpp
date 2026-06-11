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

    ll rev=0;
    for(int i=0;i<x;i++) {
        int t;
        cin>>t;

        if(t==2) {
            if(rev%2!=0) {
                reverse(s.begin(),s.end());
            }
            rev=0;
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
            rev++;
        }
    }
    if(rev%2!=0) {
        reverse(s.begin(),s.end());
    }
    cout<<s<<endl;
}


