#include <bits/stdc++.h>

//#define DEBUG

using namespace std;

template <class T>
void print_vect(std::vector<T> v){
    for(int i = 0 ; i < v .size(); i++) cout << v[i] << " ";
    cout << endl;
}


void solve(){
    uint32_t X, A ;
    cin >> X >> A;
    if(X < A){
        cout << "0" << endl;
    }else{
        cout << "10" << endl;
    }
}

int main()
{
    //making data IO Fast
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /****************************/

    #ifdef DEBUG
    int TEST_CASES = 3;
    while(TEST_CASES--){
    #endif // DEBBUG

    solve();

    #ifdef DEBUG
    }
    #endif // DEBUG
    
    return 0;
}
