/**
*    author:  souzai32
*    created: 01.08.2020 23:54:56
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    string s;
    long long int k;
    cin >> s >> k;
    long long int n=s.size();
    bool all=true;
    long long int a=0,b=0;
    long long int p=0;

    rep(i,n-1) if(s.at(i)!=s.at(i+1)) all=false;

    if(!all){
        if(s.at(0)==s.at(n-1)){
            while(1){
                a++;
                if(s.at(0)!=s.at(a)) break;
            }
            while(1){
                b++;
                if(s.at(n-1)!=s.at(n-1-b)) break;
            }
        }

        rep(i,n-1){
            if(s.at(i)==s.at(i+1)){
                s.at(i+1)=' ';
                p++;
            }
        }
    }
    
    long long ans;
    if(all) ans=n*k/2;
    else ans=p+(k-1)*(p-a/2-b/2+(a+b)/2);

    cout << ans << endl;
    //cout << a << ' ' << b << ' ' << p << endl;
}