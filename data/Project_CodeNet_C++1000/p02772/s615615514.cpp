/*
      author  : nishi5451
      created : 15.08.2020 13:55:47
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    rep(i,n){
        int a;
        cin >> a;
        if(a%2==0){
            if(a%3==0 || a%5==0){
                continue;
            }
            else{
                cout << "DENIED" << endl;
                return 0;
            }
        }
    }
    cout << "APPROVED" << endl;
    return 0;
}