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
    int k, n;
    cin >> k >> n;
    vi a(n);
    for(int i = 0; i < n ; i++){
        cin >> a[i];
    }
    int min_distance = a[n-1];
    for(int i = 0 ; i < n ; i++){
        int start = a[i];
        int end1 = a [ ( n - 1 + i) % n];
        int end2 = a[ ( i + 1 ) % n];
        int dist1 = (end1 - start);
        int dist2 = start - end2;
        //cout << dist1 << " " << dist2 << endl;
        if( dist1 < 0){
            dist1 = dist1 + k;
        }
        if(dist2 < 0){
            dist2 = dist2 + k;
        }
        if( min_distance > min(dist1, dist2)){
            min_distance = min(dist1, dist2);
        }
    }
    cout << min_distance << endl;
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

