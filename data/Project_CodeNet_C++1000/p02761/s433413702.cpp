#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()

int main() {
    int n,m,s,g;
    cin>>n>>m;
    vector<int>a(m),b(m);
    rep(i,m)cin>>a[i]>>b[i];
    if(n==1){
        s=0;
        g=10;
    }
    else{
        s=pow(10,n-1);
        g=s*10;
    }
    string h;
    int c;
    for(int i=s;i<g;i++){
        h=to_string(i);
        c=1;
        rep(j,m){
            if(h[a[j]-1]-'0'!=b[j])c=0;
        }
        if(c){
            cout<<i;
            return 0;
        }
        
    }
    cout<<-1;
	return 0;
}
