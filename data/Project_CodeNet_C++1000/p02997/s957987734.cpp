#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N,K;
    cin >> N >> K;
    if (K > (N - 1) * (N - 2) / 2) cout << -1 << endl;
    else{
        cout << (N - 1) + (N - 1) * (N - 2) / 2 - K << endl;
        for (int i = 2; i <= N; i++){
            cout << 1 << " " << i << endl;
        }
        int count = 0;
        for (int i = 2; i <= N; i++){
            for (int j = i + 1; j <= N; j++){
                if (count < (N - 1) * (N - 2) / 2 - K){
                    cout << i << " " << j << endl;
                    count++;
                }
            }
        }
    }
}