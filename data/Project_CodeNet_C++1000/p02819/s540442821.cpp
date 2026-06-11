#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;

int main(){
    int X;
    int ans;
    cin >> X;
    bool flag = true;
    if(X==2) cout << X << endl;
    else{
    while(flag){
        bool prime = true;
        for(int i=2; i < sqrt(X)+1; ++i){
            if(X % i == 0){
                prime = false;
                break;
            }
        }
        if(prime){
            flag = false;
        }
        else X++;
    }
    cout << X << endl;
    }
}