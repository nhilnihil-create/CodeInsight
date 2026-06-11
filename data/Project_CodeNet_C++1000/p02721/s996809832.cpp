#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

const int N_MAX = 200005;

int L[N_MAX];
int R[N_MAX];

int main(){
    int n, k, c;
    cin >> n >> k >> c;
    string S;
    cin >> S;

    int kmax = 1;
    int nw = -c - 5;
    for(int i = 0; i < n; i++){
        if (nw + c < i && S[i] != 'x'){
            nw = i;
            L[kmax] = i;
            kmax++;
        }
    }
    nw = n + c + 5;
    int kn = k;
    for(int i = n-1; i >= 0; i--){
        if (nw - c > i && S[i] != 'x'){
            nw = i;
            R[kn] = i;
            kn--;
        }
        if (kn == 0)break;
    }
    bool ans = false;
    for(int i = 1; i <= k; i++){
        if (L[i] == R[i]){
            cout << L[i] + 1 << endl;
            ans = true;
        }
    }
    if (!ans)cout << endl;
    return 0;
}