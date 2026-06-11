#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int main(){
    int k;
    string s;
    cin >> k >> s;
    if(s.size()<=k){
        cout << s << endl;
        return 0;
    }
    rep(i,k){
        cout << s.at(i);
    }
    cout << "..." << endl;
    return 0;
}