#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, k) for (int i = (s); i < (int)(k); i++)

int main(){
    vector<vector<int>> A(3,vector<int>(3));
    rep(a,0,3){
        rep(b,0,3){
            cin >> A.at(a).at(b);
        }
    }
    
    int n;
    cin >> n;
    
    vector<vector<bool>> C(3,vector<bool>(3,false));
    vector<int> B(n);
    rep(i,0,n){
        cin >> B.at(i);
        rep(k,0,3){
            rep(j,0,3){
                if(A.at(k).at(j)==B.at(i)){
                    C.at(k).at(j) = true;
                }
            }
        }
    }
    bool ans = false;

    rep(j,0,3){
        if(C.at(0).at(j)&&C.at(1).at(j)&&C.at(2).at(j)) ans= true;
        if(C.at(j).at(0)&&C.at(j).at(1)&&C.at(j).at(2)) ans= true;
    }
   if(C.at(0).at(0)&&C.at(1).at(1)&&C.at(2).at(2)) ans= true;
   if(C.at(2).at(0)&&C.at(1).at(1)&&C.at(0).at(2)) ans= true;

   cout << ((ans) ? "Yes" : "No" )<< endl;

}