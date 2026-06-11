/**
*    author:  souzai32
*    created: 02.08.2020 13:31:43
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n;
    int a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    string s;
    cin >> s;

    bool rock=false;
    bool ans=true;

    for(int i=a; i<d; i++){
        if(s.at(i)=='#'){
            if(rock) ans=false;
            else rock=true;
        }
        if(s.at(i)=='.') rock=false;
        if(!ans) break;
    }

    if(c>d){
        int count=0;
        ans=false;
        for(int i=b-2; i<min(d+1,n); i++){
            if(s.at(i)=='.') count++;
            else count=0;
            if(count>=3){
                ans=true;
                break;
            }
        }
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}