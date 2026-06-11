#include <iostream>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)

#include <string>
#include <vector>
#include <algorithm>
int main(){
    int n,k,q; cin >> n >> k >> q;
    if(k>q) {
        rep(i,n) cout << "Yes" << endl;
        return 0;
    }
    vector<int> succes(n+1);
    int num;
    rep(i,q){
        cin >> num;
        succes[num]++;
    }
    int ans = 0;
    rep(i,n){
        if(k-q+succes[i+1]<=0){
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
}