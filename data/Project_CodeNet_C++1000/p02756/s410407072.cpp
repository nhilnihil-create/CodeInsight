/**
*    author:  souzai32
*    created: 02.08.2020 14:04:13
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    string S;
    cin >> S;
    int n=S.size();
    vector<char> s(n);
    rep(i,n) s.at(i)=S.at(i);

    int q;
    cin >> q;
    int t,f;
    char c;
    int rev=0;
    rep(i,q){
        cin >> t;
        if(t==1){
            rev+=1;
        }
        else{
            cin >> f >> c;
            if((rev+f)%2){
                auto it=s.begin();
                it=s.insert(it,c);
            }
            else s.push_back(c);
        }
    }
    if(rev%2) reverse(s.begin(),s.end());

    rep(i,s.size()) cout << s.at(i);
    cout <<  endl;

    return 0;
}