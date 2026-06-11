#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int main(){
    int x,n;
    cin >> x >> n;
    set<int> s;
    rep(i,n){
        int a; cin >> a;
        s.insert(a);
    }
    int dx=0;
    while(1){
        if(!(s.count(x-dx))){
            cout << x-dx << endl;
            break;
        }
        if(!(s.count(x+dx))){
            cout << x+dx << endl;
            break;
        }
        dx++;
    }
}