#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int inf = 1000000000;

int main(){
    int n;
    cin >> n;
    //int ans = 0;
    vector<int> a(1e6+1);
    rep(i,1e6+1) a.at(i)=0;
    set<int> s;
    rep(i,n){
        int b;
        cin >> b;
        if(s.count(b)) a.at(b)++;
        s.insert(b);
    } 
    for(int i=1; i<=1e6; i++){
        if(s.count(i)>=1){
            for(int j=i; j<=1e6; j+=i){
                a.at(j)++;
            }
        }
    }
    int ans = 0;
    for(int i=1; i<=1e6; i++){
        if(s.count(i)>=1){
            if(a.at(i) == 1){
                ans++;
            }
        }
    }
    cout << ans << endl;
}