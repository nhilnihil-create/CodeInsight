#include <bits/stdc++.h>
#include <list>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 100000007;
using Graph = vector<vector<int>>;


int main(){
    string S;
    cin >> S;
    string Sp;
    Sp = S;
    reverse(Sp.begin(),Sp.end());
    S.reserve(300100);
    Sp.reserve(300100);
    bool reversed = false;
    int Q;
    cin >> Q;
    REP(i,Q){
        int t;
        cin >> t;
        if(t==2){
            int f;
            cin >> f;
            char c;
            cin >> c;
            if(f==1){
                if(reversed){
                    S.push_back(c);
                    Sp.insert(Sp.begin(),c);
                }
                else{
                    Sp.push_back(c);
                    S.insert(S.begin(),c);
                }
            }
            else{
                if(!reversed){
                    S.push_back(c);
                    Sp.insert(Sp.begin(),c);
                }
                else{
                    Sp.push_back(c);
                    S.insert(S.begin(),c);
                }
            }
        }
        else{
            if(reversed) reversed = false;
            else reversed = true;
        }
    }
    if(reversed) cout << Sp << endl;
    else cout << S << endl;
}