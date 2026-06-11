#include <bits/stdc++.h>

//#define DEBUG

using namespace std;

template <class T>
void print_vect(std::vector<T> v){
    for(int i = 0 ; i < v .size(); i++) cout << v[i] << " ";
    cout << endl;
}


void solve(){
    uint64_t W, H , X, Y ;
    cin >> W >> H >> X >> Y;
    uint64_t surface =  W * H;    
    double ans = surface / 2.0;
    if( X * 2 == W && Y * 2 == H){
        cout << ans << " 1" << endl;
    }else{
        cout << ans << " 0" << endl;
    }
}

int main()
{
    //making data IO Fast
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /****************************/

    #ifdef DEBUG
    int TEST_CASES = 2;
    while(TEST_CASES--){
    #endif // DEBBUG

    solve();

    #ifdef DEBUG
    }
    #endif // DEBUG
    
    return 0;
}
