#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void){
    string S;
    cin >> S;

    int N = S.size() + 1;

    vector<int> a(N);
    vector<int> lt_succ(N); // < 
    vector<int> gt_succ(N); // >

    gt_succ[0] = 0;
    lt_succ[N-1] = 0;

    for(int i = 0; i < N - 1; i++){
        if(S[i] == '<'){
            lt_succ[i+1] = lt_succ[i] + 1;
        } else {
            lt_succ[i+1] = 0;
        }

        if(S[N - 2 - i] == '>'){
            gt_succ[N-2-i] = gt_succ[N - 1 - i] + 1;
        } else {
            gt_succ[N-2-i] = 0;
        }
    }


    ll sum = 0;

    for(int i = 0; i < N; i++){
        sum += max(gt_succ[i], lt_succ[i]);
    }
    
    cout << sum << endl;

    return 0;
}
