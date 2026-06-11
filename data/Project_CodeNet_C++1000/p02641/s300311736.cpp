#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const ll MOD = 1000000007;
ll cnt =0,ans=0;
const int MAX = 510000;

int main(){
    int x,n;
    cin >> x >> n;
    vector<int> p(n);
    for(int i=0;i<n;i++){
        cin >> p.at(i);
    }

    
        for(int i=0;i<110;i++){
            bool lc,rc;
            lc = false;
            rc = false;
            int l = x-i;
            int r = x+i;
                
            for(int j=0;j<n;j++){
                
                if(p.at(j) == l) lc = true;
                if(p.at(j) == r) rc = true;
            }
            if(lc == false && rc == false){
                cout << l << endl;
                return 0;}

            if(lc && rc == false){
                cout << r << endl;
                return 0;}

            if(lc == false && rc){
                cout << l << endl;
                return 0;
                }
        }
    
}