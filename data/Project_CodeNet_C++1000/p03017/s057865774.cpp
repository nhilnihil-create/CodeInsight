#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }


int main(){
    ll N , A ,B ,C , D;
    string S;
    cin >> N >> A >> B >> C >> D >> S;

    A--;
    B--;
    C--;
    D--;

    ll streak_p = 1;

    bool flag_swap = false;
    bool flag_A = true;
    bool flag_B = true;

    for(int i = B - 1; i <= D; i++){
        if(S[i] == S[i + 1] && S[i] == '.'){
            streak_p++;
            if(streak_p >= 3) flag_swap = true;
        }else{
            streak_p = 1;
        }
    }

    for(int i = A ; i < C; i++){
        if(S[i] == S[i + 1] && S[i] == '#'){
            flag_A = false;
        }
    }

    for(int i = B ; i < D; i++){
        if(S[i] == S[i + 1] && S[i] == '#'){
            flag_B = false;
        }
    }

    if(flag_A == false || flag_B == false){
        cout << "No" << endl;
        return 0;
    }



    if(D < C && flag_swap){
        cout << "Yes" << endl;
        return 0;
    }else if(C < D){
        cout << "Yes" << endl;
        return 0;
    }else{
        cout << "No" << endl;
        return 0;
    }


}
