#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<string>
#define MOD 1000000007
#define enld endl
typedef long long ll;
using namespace std;

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int H,W,K; cin >> H >> W >> K;
    char c[10][10];
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> c[i][j];
        }
    }

    int ans = 0;

    for(int i=0;i<(1<<H);i++){
        for(int j=0;j<(1<<W);j++){
            char copy[10][10];
            for(int i=0;i<10;i++){
                for(int j=0;j<10;j++){
                    copy[i][j] = c[i][j];
                }
            }
            for(int k=0;k<H;k++){
                if(i & (1 << k)){
                    for(int l=0;l<W;l++){
                        copy[k][l] = 'r';
                    }
                }
            }
            for(int k=0;k<W;k++){
                if(j & (1 << k)){
                    for(int l=0;l<H;l++){
                        copy[l][k] = 'r';
                    }
                }
            }

            int cnt = 0;
            for(int k=0;k<H;k++){
                for(int l=0;l<W;l++){
                    if(copy[k][l] == '#') cnt++;
                }
            }
            if(cnt == K) ans++;
        }
    }

    cout << ans << enld;
    return 0;
}