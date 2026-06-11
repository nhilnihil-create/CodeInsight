#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    string S;
    int Q;
    cin >> S>> Q;
    vector<int> T(Q,0);
    vector<int> F(Q,0);
    vector<char> C(Q, 0);
    for(int i = 0; i < Q; i++){
        cin >> T[i];
        if(T[i] == 2){
            cin >> F[i] >> C[i];
        }
    }

    string head = "";
    string tail = "";
    vector<int> flip(Q, 0);
    int sum = 0;
    for(int i = 0; i < Q; i++){
        sum += T[Q - i - 1];
        sum %= 2;
        flip[Q - i - 1] = sum;
    }

    if(sum != 0){
        reverse(S.begin(), S.end());
    }

    for(int i = 0; i < Q; i++){
        if(T[i] == 2){
            if(F[i] == 1){
                if(flip[i] == 0){
                    head = C[i] + head;
                } else {
                    tail = tail + C[i];
                }
            } else {
                if(flip[i] == 0){
                    tail = tail + C[i];
                } else {
                    head = C[i] + head;
                }
            }
        }
    }

    cout << head + S + tail << endl;

    return 0;
}
