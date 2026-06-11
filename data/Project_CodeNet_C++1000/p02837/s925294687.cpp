#include <iostream>
using namespace std;

typedef long long ll;
#define rep1(i, n) for(int i = 1; i <=(ll)(n); i++)
#define rep0(i, n) for(int i = 0; i <=(ll)(n); i++)

int main(){
    int n;
    cin >> n;
    int x[20][20];
    int y[20][20];
    int a[20];
    bool all_not_told = true;
    rep1(i, n){
        cin >> a[i];
        if(a[i] > 0) all_not_told = false;
        rep1(j,a[i]) cin >> x[i][j] >> y[i][j];
    }
    
    if(all_not_told){
        cout << n << endl;
        return 0;
    }

    if(n == 1) cout << 1 << endl;

    int max_honest_count = 0;
    // {0, 1, ..., n-1} の部分集合の全探索
    for(int bit = 1; bit < (1<<n); ++bit){        
        int honest_count = 0;
        bool contradiction = false;
        rep1(i, n){
            if(bit & (1<<(i-1))) { // i が bit に入るかどうか
                honest_count++;
                rep1(j, a[i]){
                    if( ((bit >> (x[i][j]-1) ) & 1) ^ y[i][j]){
                        contradiction = true;
                        break;
                    }
                }
            }
        }
        if(!contradiction) max_honest_count = max(honest_count, max_honest_count);
    }
    cout << max_honest_count << endl;
    return 0;
}