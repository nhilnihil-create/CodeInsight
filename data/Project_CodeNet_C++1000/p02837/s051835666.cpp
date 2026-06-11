#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793


int main(){
    int n;
    cin >> n;
    VI a(n);
    vector<VI> x(n,VI(n));
    vector<VI> y(n,VI(n));
    rep(i,n){
        cin >> a.at(i);
        rep(j,a.at(i)){
            cin >> x.at(i).at(j) >> y.at(i).at(j);
        }
    }
    int mx=0;
    for(int bit=0;bit< (1<<n);bit++){
        set<int> good;
        bool chk=true;
        rep(k,n){
            if(bit & (1<<k)){
                good.insert(k+1);
            }
        }
        rep(i,n){
            if(good.count(i+1)){
             rep(j,a.at(i)){
                if(y.at(i).at(j)==1){
                    if(good.count(x.at(i).at(j)));
                    else{ 
                    chk=false;
                    break;
                    }
                }
                else if(y.at(i).at(j)==0){
                    if(good.count(x.at(i).at(j))){
                        chk=false;
                        break;
                    }
                }
             }
            }
            if(chk);
            else break;
        }
        if(chk){
            int m=good.size();
            mx=max(mx,m);
        }
    }
    cout << mx << endl;
}

    