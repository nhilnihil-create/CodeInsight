#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;

typedef int64_t ll;

template <class T1, class T2>
using dict = std::unordered_map<T1, T2>;

int main(){
    int H,W,A,B;
    cin >> H >> W >> A >> B;
    REP(i,H){
        REP(j,W){
            if ((i<B && j<A)||(i>=B && j>=A)) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }

} 