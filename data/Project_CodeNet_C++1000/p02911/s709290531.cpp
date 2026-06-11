
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long
const int inf = 1000000000;

int main(){
 int n,k,q;
 cin >> n >> k >> q;
    vector<int> h(n);
    rep(i,n){
        h[i]=k-q;
    }
    rep(i,q){
        int x;
        cin >> x;
        h[x-1]++;
        }
        rep(i,n){
            if(h[i]>0){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
        return 0;
}