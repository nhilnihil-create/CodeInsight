#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

int main(){
    string t;
    cin>>t;

    int n=t.length();
    rep(i, n) if(t[i]=='?') t[i]='D';

    cout << t << endl;
    return 0;
}
