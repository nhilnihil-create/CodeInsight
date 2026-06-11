#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<string>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;

using namespace std;

int main(){
    int N, K, R, S, P; 
    string T;
    char c;
    cin >> N >> K >> R >> S >> P >> T;
    vector<int> v(N,0);
    int score = 0;
    rep(i,N){
        c = T[i];
        if(c == 'r'){
            if((i >= K && v[i-K] != 3) || i < K){
                v[i] = 3;
                score += P;
            }
        }else if(c == 's'){
            if((i >= K && v[i-K] != 1) || i < K){
                v[i] = 1;
                score += R;
            }
        }else{
            if((i >= K && v[i-K] != 2) || i < K){
                v[i] = 2;
                score += S;
            }
        }
    }
    cout << score << endl;
    return 0;
}