#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    int ans = 0;
    for (int i = 0; i < N; i++){
        string T = S.substr(i, N - i);
        vector<int> A(N - i + 1, 0);
        int j = -1;
        A[0] = -1;
        for (int k = 0; k < N - i; k++){
            while(j >= 0 && T[k] != T[j]) j = A[j];
            j++;
            A[k + 1] = j;
        }
        for (int k = 1; k < N - i + 1; k++){
            if (k >= A[k] * 2){
                ans = max(ans, A[k]);
            }
            else{
                ans = max(ans, k / 2);
            }
        }
    }
    cout << ans << endl;
}
