#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vc = vector<char>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using ll = long long int;

int main(){
    ll N, A, B, C, D; cin >> N >> A >> B >> C >> D;
    vc S(N+1);
    for(int i=1; i<N+1; i++){
        cin >> S[i];
    }
    if(C<D){
        bool m = true;
        for(int i=A+1; i<D-1; i++){
            if(S[i]=='#'&&S[i+1]=='#'){
                m = false;
            }
        }
        if(m == true){
            cout << "Yes";
        }else{
            cout << "No";
        }
    }else{
        bool m = true;
        for(int i=A+1; i<C-1; i++){
            if(S[i]=='#'&&S[i+1]=='#'){
                m = false;
            }
        }
        bool n = false;
        for(int i=B-1; i<D; i++){
            if(S[i]=='.'&&S[i+1]=='.'&&S[i+2]=='.'){
                n = true;
            }
        }
        if(m==true&&n==true){
            cout << "Yes";
        }else{
            cout << "No";
        }
    }
}