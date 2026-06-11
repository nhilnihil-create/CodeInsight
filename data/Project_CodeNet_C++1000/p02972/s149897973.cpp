    #include <bits/stdc++.h>
    #include<math.h>
    #define rep(i,n) for (int i = 0; i < (n) ; ++i)
    using namespace std;
    using ll = long long ;
    using P = pair<int , int> ;
    #define PI 3.14159265358979323846264338327950
    #define INF 1e18 
     
    int main() {
        int n ;
        cin >> n ;
        vector<int> a (n + 1) ;
        rep(i, n){
            cin >> a[i + 1] ;
        }
        vector<int> b (n + 1) ;
        for(int i = n ; i >= 1 ; i--){
            int sum = 0 ;
            for(int j = i ; j <= n ; j += i){
                sum += b[j] ;
            }
            if(sum % 2 == a[i]){
                b[i] = 0 ;
            }
            else {
                b[i] = 1 ;
            }
        }
        vector<int> ans ; 
        rep(i, n){
            if(b[i + 1] == 1){
                ans.push_back(i + 1) ;
            }
        }
        cout << ans.size() << endl ;
        if(ans.size() != 0){
            for(int u : ans){
                cout << u << " ";
            }
            cout << endl ;
        }
    }