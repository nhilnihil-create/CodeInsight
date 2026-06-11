#include <bits/stdc++.h>

//#define DEBUG

using namespace std;

template <class T>
void print_vect(std::vector<T> v){
    for(int i = 0 ; i < v .size(); i++) cout << v[i] << " ";
    cout << endl;
}


void solve(){
    uint32_t N, X ;
    cin >> N >> X ;
    std::vector<uint32_t> L;
    L.reserve(N);
    for(uint32_t i = 0 ; i < N ; ++i){
        uint32_t l ;
        cin >> l;
        L.push_back(l);
    }
    uint32_t D = 0;
    for(uint32_t i = 0 ; i < N ; ++i){
       D = D + L[i];
       if( D > X) 
       {
           cout << i + 1 << endl;
           return;
       }
    }
    cout << N + 1 << endl;
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
