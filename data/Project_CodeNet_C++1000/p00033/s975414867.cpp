#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

#define loop(i,a,b) for(int i=(a);i<ull(b);++i)
#define rep(i,n) loop(i,0,n)

int main(){
    int n;
    cin >> n;
    rep(p, n){
        vector<int> v(10);
        rep(i,10) cin >> v[i];
        int a=0, b=0;
        bool is = true;
        for(int i=0; i < 10; i++){
            if(v[i] < a && v[i] < b){is = false; break;}
            if(a < b) (b<v[i]?b:a) = v[i];
            else (a<v[i]?a:b) = v[i];
        }
        cout << (is?"YES":"NO") << endl;
    }
}