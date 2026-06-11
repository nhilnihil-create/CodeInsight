#include "bits/stdc++.h"
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >>s;

    int cnt=0;
    int mx=0;

    for(char i : s){
        if(i=='R')cnt++;
        else cnt=0;
        mx=max(mx,cnt);
    }
    cout<<mx<<endl;
}

