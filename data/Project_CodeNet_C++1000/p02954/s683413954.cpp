#include <bits/stdc++.h>
#include<math.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int , int> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18 


int main () {
    string s ;
    cin >> s ;
    int n = s.size() ;
    vector<int> ans (n) ;
    rep(j, 2){
        int num = 0 ;
        rep(i, n){
            if(s[i] == 'R'){
                num++ ; 
            }
            else {
                int rm = num - (num / 2) ;
                ans[i] += num/2 ;
                ans[i - 1] += rm ;
                num =  0 ;
            }
        }
        rep(i, n){
            if(s[i] == 'R'){
                s[i] = 'L' ;
            }
            else {
                s[i] = 'R' ;
            }
        }
        reverse(s.begin(),s.end()) ;
        reverse(ans.begin(), ans.end()) ;
    }

    
    rep(i, n){
        cout << ans[i] << " " ;
    }
    cout << endl ;
} 
