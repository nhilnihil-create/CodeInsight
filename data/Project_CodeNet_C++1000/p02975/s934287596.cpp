    #include<iostream>
    #include<stdio.h>
    //#include <bits/stdc++.h>
    #include<vector>
    #include<float.h>
    #include<iomanip>
    #include<algorithm>
    #include<string>
    #include<cstring>
    #include<math.h>
    #include<cmath>
    #include<sstream>
    #include<set>
    #include<map>
    #include<queue>
    #include<cassert>
    #include<cmath>
    #include<cstdint>
     
    #define INF 1e9
    #define rep(i,n)for(int i=0;(i)<(int)(n);i++)
    #define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
    #define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
    #define vec(type,n) vector<type>(n)
    #define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
    #define ALL(a)  (a).begin(),(a).end()
    #define chmin(a, b) a = min(a, b)
    #define chmax(a, b) a = max(a, b)
    #define pb push_back
    #define sz size()
     
    using namespace std;
    using ll = long long int;
    using Graph = vector<vector<int>>;
    using P = pair<ll, ll>;
    using Vl = vector<ll>;
     
const int MOD = 1e9 + 7;
const ll ZER = 0;


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> st;

    rep(i, n){
        cin >> a[i];
        st.insert(a[i]);
    }
    if(st.size() == 1){
        if(a[0] == 0)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    if(st.size() == 2){
        int x = 0, z = 0;
        rep(i, n){
            if(a[i] == 0)z++;
            else x++;
        }
        if(n % 3 == 0 && x == n / 3 * 2 && z == n / 3)cout << "Yes" << endl;
        else cout << "No" << endl;
        //cout << "hoge";
    }
    if(st.size() == 3){
        bool f = true;
        map<ll, int> mp;
        rep(i, n)mp[a[i]]++;
      	int x = 0;
        for(auto m : mp){
          	x ^= m.first;
            if(m.second * 3 != n)f = false;
        }
        if(f && n % 3 == 0 && x == 0)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    if(st.size() > 3)cout << "No" << endl;
}

