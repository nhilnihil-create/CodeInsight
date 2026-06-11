#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector <P> p(n);
    rep(i,n){
        cin >> p[i].second >> p[i].first;
    }
    sort(p.begin(), p.end());

ll t;
t=0;
int k=0;
    rep(i,n){
        t+=p[i].second;
        if(t>p[i].first){
            k=1;
            break;
        }    
    }

    if(k==1){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
    

    return 0;
}