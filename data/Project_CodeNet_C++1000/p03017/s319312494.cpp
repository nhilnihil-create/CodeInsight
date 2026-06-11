#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N,A,B,C,D;
    cin >> N >> A >> B >> C >> D;
    string S;
    cin >> S;
    S = "#" + S + "#"; // 端を石を置いておく    
    // C<Dの時は#が連続してなければ必ず可能
    if(C<D){
        for(int i=A;i<=C-1;i++){
            if(S[i]=='#'&&S[i+1]=='#'){
                cout << "No" << endl;
                return 0;
            }
        }
        for(int i=B;i<=D-1;i++){
            if(S[i]=='#'&&S[i+1]=='#'){
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    }else{
        for(int i=A;i<=C-1;i++){
            if(S[i]=='#'&&S[i+1]=='#'){
                cout << "No" << endl;
                return 0;
            }
        }
        for(int i=B;i<=D-1;i++){
            if(S[i]=='#'&&S[i+1]=='#'){
                cout << "No" << endl;
                return 0;
            }
        }
        // C>Dの時はどこかで追い越す必要がある
        // 追い越すためには　...すふ〇... の状況が必要
        // B-1のマスからD+1のマスのなかで3連続の空きがあればOK
        for(int i=B-1;i<=D-1;i++){
            if(S[i]=='.'&&S[i+1]=='.'&&S[i+2]=='.'){
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
    }
    return 0;
}