#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define per(i,n) for(int i=(n)-1; i>=0; i--)
using namespace std;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n,k,s;cin>>n>>k>>s;
    
    int buf = 1000000000;
    if(s==buf)buf = 1;
    for(int i=0; i<n; i++){
        if(i<k)cout<<s;
        else cout << buf;
        if(i!=n-1)cout << " ";
        else cout << endl;
    }
    
    return 0;
}