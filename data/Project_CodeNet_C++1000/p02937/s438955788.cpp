#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    string s,t;
    int l;
    cin >> s >> t;
    l=s.size();
    vector <vector <int>> al(26);

    rep(i,26){
        al[i].push_back(-1);
    }
    rep(i,l){
        al[s[i]-97].push_back(i);
    }


    ll ans=0;
    int k=0;
    int l2;
    int rt,lt,m;
    int l3;
    l3=t.size();

    rep(i,l3){
        l2=al[t[i]-97].size();
        //cout << l2 << endl;
        if(l2==1){
            ans=-1;
            break;
        }
        if(k>al[t[i]-97][l2-1]){
            ans+=l;
            k=0;
        }
        rt=l2-1;
        lt=0;
        while(rt-lt>1){
            m=(rt+lt)/2;
            if(al[t[i]-97][m]<k){
                lt=m;
            }
            else{
                rt=m;
            }
        }
        k=al[t[i]-97][rt];
        ++k;
        //cout << k << endl;
        if(i==(l3-1)){
            ans+=k;
        }


    }

    
    cout << ans << endl;
    

    return 0;
}