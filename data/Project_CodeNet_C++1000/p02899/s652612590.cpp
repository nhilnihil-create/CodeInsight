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
    vector<pair<int,int>> a;
    for(int i = 0 ; i < n ;i++){
        int x;
        cin >> x;
        a.push_back(make_pair(x,i));
    }
    sort(a.begin(), a.end());
    vector<int> ans(n);
    for(int i = 0 ; i < n ; i++){
        int id = a[i].second; 
        cout << id + 1 << "\n";
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