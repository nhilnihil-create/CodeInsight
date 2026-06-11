#include<bits/stdc++.h>
using namespace std;

template <class T>
using V = vector<T>;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)

int main(){
    int N;
    cin >> N;
    V<int> A(N);
    rep(i, N) cin >> A.at(i);
    
    vector<int> D(1000001, 1000000);
    
    rep2(i, 2, 1000001){
        int t = i;
        while(t<=1000000){
            if(D.at(t) == 1000000){
                D.at(t) = i;
            }
            t += i;
        }
    }
    
    set<int> divisor;
    bool flg = true; 
    rep(i, N){
        int a = A.at(i);
        set<int> div;
        while(a > 1){
            int Da = D.at(a);
            div.insert(Da);
            a /= Da; 
        }
        for(auto itr=div.begin();itr!=div.end();itr++){
            if(!divisor.insert(*itr).second) flg = false;
        }
    }

    if(flg) cout << "pairwise coprime" << endl;

    else{
        set<int> old_gcd;
        int a0 = A.at(0);
        while(a0 > 1){
            int Da = D.at(a0);
            old_gcd.insert(Da);
            a0 /= Da;
        }
        rep2(i, 1, N){
            int a = A.at(i);
            set<int> new_gcd;
            while(a > 1){
                int Da = D.at(a);
                if(old_gcd.find(Da) != old_gcd.end()) new_gcd.insert(Da);
                a /= Da; 
            }
            old_gcd = new_gcd;
            new_gcd.clear();
        }

        if(old_gcd.empty()) cout << "setwise coprime" << endl;
        else cout << "not coprime" << endl;
    }
}