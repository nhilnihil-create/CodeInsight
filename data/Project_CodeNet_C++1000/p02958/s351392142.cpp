/*
      author  : nishi5451
      created : 15.08.2020 11:29:32
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    vector<int> p(n),q;
    rep(i,n) cin >> p[i];
    q = p;
    sort(q.begin(),q.end());
    if(p==q){
        cout << "YES" << endl;
        return 0;
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            vector<int> r(p);
            swap(r[i],r[j]);
            /*bool check = true;
            rep(m,n){
                if(r[m]!=q[m]){
                    check = false;
                    break;
                }
            }
            if(check==true){*/
            if(r==q){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}