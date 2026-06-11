#include <bits/stdc++.h>//復習必須
#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
int main () {
    ll A , B , M;
    cin >> A >> B >> M ;
    vector<int> a(A);
    vector<int> b(B);
    rep(i ,A ){
      cin >> a[i] ;
    }

    rep(j ,B ){
      cin >> b[j] ;
    }

    int minA = *min_element(a.begin(), a.end());
    int minB = *min_element(b.begin(), b.end());
    ll ans = minA + minB ;
    
    ll kari , x , y , c;
    rep(k ,M){
        cin >> x >> y >> c ;
        kari= a[x-1] + b[y-1] -c ;
        ans = min(ans, a[x-1] + b[y-1] - c);

    }

    cout << ans << endl;
    return 0 ;
}

 
