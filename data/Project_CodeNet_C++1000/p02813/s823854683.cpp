#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;
 

int main(){
    int n;
    cin >> n;
    vector<int> p(n),q(n);
    rep(i,n) cin >> p[i];
    rep(i,n) cin >> q[i];
    vector<bool> p_check(n+1,true);
    vector<bool> q_check(n+1,true);
    int p_num = 0;
    int q_num = 0;
    vector<int> fact(n+1);
    fact[0]=1;
    for(int i=1; i<n; i++){
        fact[i] = fact[i-1]*i; 
        //cout << fact[i] << endl;
    }
    rep(i,n){
        int k = 0;
        for(int j=1; j<p[i]; j++){
            if(p_check[j]==true) k++;
        }
        p_num += fact[n-i-1]*k;
        p_check[p[i]] = false;
    }
    rep(i,n){
        int k = 0;
        for(int j=1; j<q[i]; j++){
            if(q_check[j]==true) k++;
        }
        q_num += fact[n-i-1]*k;
        q_check[q[i]] = false;
    }
    cout << abs(p_num - q_num) << endl;
    
    return 0;
}