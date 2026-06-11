#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;

using namespace std;

int main(){
    int N, A, B, C, D;  cin >> N >> A >> B >> C >> D;
    string S;   cin >> S;
    S += "###";
    S = '#' + S;
    int a, b;
    a = A;
    b = B;
    if(D > C){
        while(b < D){
            if(S[b+1] == '.')   b++;
            else{
                if(S[b+2] == '.')   b += 2;
                else{print("No"); return 0;}
            }
        }
        while(a < C){
            if(S[a+1] == '.')   a++;
            else{
                if(S[a+2] == '.')   a += 2;
                else{print("No"); return 0;}
            }
        }
        print("Yes");
    }else{
        while(b < D){
            if(S[b-1] == '.' && S[b+1] == '.'){
                break;
            }else{
                if(S[b+1] == '.')   b++;
                else{
                    if(S[b+2] == '.')   b += 2;
                    else{print("No"); return 0;}
                }
            }
        }
        S[b] = 'B';
        while(a < C){
            if(S[a+1] == '.')   a++;
            else{
                if(S[a+2] == '.')   a += 2;
                else{print("No"); return 0;}
            }
        }
        print("Yes");
    }
}