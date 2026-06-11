#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin >> s;
    string s_rev = s;
    reverse(s_rev.begin(),s_rev.end());
    if(s==s_rev){
        string l,r;
        l = s.substr(0,(int(s.size())-1)/2);
        r = s.substr(int(s.size())/2+1,s.size()/2);
        string l_rev = l, r_rev = r;
        reverse(l_rev.begin(),l_rev.end());        
        reverse(r_rev.begin(),r_rev.end());        
        if(l==l_rev && r==r_rev){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}