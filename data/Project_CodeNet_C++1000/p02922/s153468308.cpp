#include <bits/stdc++.h>
//#define DEBUG
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
template <class T>
void print_vect(std::vector<T> v){
    for(int i = 0 ; i < v .size(); i++) cout << v[i] << " ";
    cout << endl;
}

void solve(){
    int A, B;
    cin >> A >> B;
    if( B == 1){
        cout << 0 << endl;
        return;
    }
    int ans = ( B - A) / (A - 1);
    if( B <= A){
        cout << 1 << endl;
        return;
    }
    if( (B - A) % (A-1) == 0){
        ans = ans + 1;
    }else{
        ans = ans + 2;
    }
    cout << ans << endl;
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

