#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define ll long long

int main(){
    int n;
    cin >> n;
    vector<int> p(n),q(n),jisho(n);
    rep(i,n){
        cin >> p.at(i);
    }
    rep(i,n){
        cin >> q.at(i);
    }
    rep(i,n){
        jisho.at(i) = i+1;
    }
    int a,b,count=0;
    do{
        count++;
        rep(i,n){
            if(p==jisho){
                a=count;
            }
            if(q==jisho){
                b=count;
            }
        }
    }while(next_permutation(jisho.begin(),jisho.end()));
    cout << abs(a-b) << endl;
    return 0;
}
