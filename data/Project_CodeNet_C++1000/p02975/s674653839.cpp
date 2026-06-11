/**
*    author:  souzai32
*    created: 07.08.2020 18:29:54
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    sort(a.begin(),a.end());
    bool ans=false;

    if(a.at(n-1)==0) ans=true;
    if(n%3==0){
        if(a.at(0)==a.at(n/3-1) && a.at(n/3)==a.at(2*n/3-1) && a.at(2*n/3)==a.at(n-1)){
            int x=a.at(0),y=a.at(n/3),z=a.at(2*n/3);
            ans=true;
            while(x>0||y>0||z>0){
                if((x%2+y%2+z%2)%2){
                    ans=false;
                    break;
                }
                else{
                    x/=2;
                    y/=2;
                    z/=2;
                }
            }
        }
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}