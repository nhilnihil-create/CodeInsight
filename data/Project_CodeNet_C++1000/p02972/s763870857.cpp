#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n;
    cin >> n;
    int aa;
    vector <int> a(n+1);
    rep(i,n){
        cin >> aa ;
        if(aa==0){
            a[i+1]=-1;
        }
        else{
            a[i+1]=1;
        }
    }

    vector <vector <int>> memo(n+1);

    int k,k2;
    rep(i,n){
        k=2;
        while((i+1)*k<=n){
            memo[(i+1)*k].push_back(i+1);
            ++k;
        }
    }

    int ka;
    ka=0;
    int l;
    vector <int> ans(n+1,0);
    for (int i=n; i>0;--i){
        if(a[i]==1){
            ++ka;
            ans[i]=1;
            if(memo[i].size()!=0){
                    l=memo[i].size();
                    rep(j,l){ 
                        a[memo[i][j]]*=-1;
                    }
        }
        }
    }

    cout << ka <<endl;
    rep(i,n){
        if(a[i+1]==1){
            cout << i+1 << endl;
        }
    }

    

    return 0;
}