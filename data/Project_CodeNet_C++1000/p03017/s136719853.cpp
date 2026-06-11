#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int N, A, B, C, D;
    string S;
    cin >> N >> A >> B >> C >> D >> S;

    for (int i = A-1; i < C-1; i++)
    {
        if(S[i] == S[i+1] && S[i] == '#'){
            cout << "No" << endl;
            return 0;
        }
    }

    for (int i = B-1; i < D-1; i++)
    {
        if(S[i] == S[i+1] && S[i] == '#'){
            cout << "No" << endl;
            return 0;
        }
    }

    if(C < D){
        cout << "Yes" << endl;
    } else {
        bool ok = false;
        for(int i = B-1; i <=D-1; i++){
            if(S[i] == '.' && S[i-1] == '.' && S[i+1] == '.'){
                ok = true;
            }
        }

        if(ok) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
