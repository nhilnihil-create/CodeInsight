#include <iostream>
#include<vector>
#include<algorithm>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for (int i = s; i < t; i++)
#define rng(a) a.begin(),a.end()
using ll = long long;

using namespace std;



int main() {
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    rep(i,n){
        cin>>a[i];
        b[i] = a[i];
    }
    sort(rng(b));
    rep(i,n){
        if(a[i] == b[n-1]){
            cout<<b[n-2]<<endl;
        }
        else cout<<b[n-1]<<endl;
    }

    return 0;
}
