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
    int n; 
    cin >> n;
    vi d(n);
    for(int i = 0 ; i < n ; i++){
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    int lb = d[(n-1)/2] + 1;
    int rb = d[n/2];
    int ans = rb - lb + 1;
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

//My mistake:
// I did not read the problem properly
// I can start from anywhere
// Hence, optimal path should have only one direction!!!!
//Again, this is C. So I should expect it to have a simple solution