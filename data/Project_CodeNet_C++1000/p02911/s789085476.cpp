#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define reps(i,s,n) for (int i = (s); i <= (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    
    int N , K , Q;
    cin >> N >> K >> Q;
    int A[Q];

    for(int i = 0; i < Q; i++){
        cin >> A[i];
    }
    vector<int> score(N, K - Q);

    for(int i = 0; i < Q; i++){
        score[A[i] - 1]++;
    }

    for(auto v:score){
        if(v <= 0)
            cout << "No" << endl;
        else 
            cout << "Yes" << endl;
    }
 
    // for(int i = 0; i < Q; i++){
    //     cin >> A[i];
    // }
    // vector<int> score(N, K);

    // for(int i = 0; i < Q; i++){
    //     int a = A[i];
    //     for(int j = 0; j < N; j++){
    //         if(j != A[i] - 1){
    //             score[j]--;
    //         }
    //     }
    // }

    // for(auto v:score){
    //     if(v <= 0)
    //         cout << "No" << endl;
    //     else 
    //         cout << "Yes" << endl;
    // }
    

    return 0;
}