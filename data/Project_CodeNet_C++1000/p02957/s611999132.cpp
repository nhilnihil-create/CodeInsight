#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); ++i)
using ll = long long;

int main(){
    int a,b; cin >> a >> b;
    if(a<b) swap(a,b);
    int d = abs(a-b);
    if(d%2==0){
        cout << a - d/2 << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
}