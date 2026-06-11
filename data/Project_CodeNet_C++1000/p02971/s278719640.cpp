#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
typedef vector<int> vec;
typedef vector<int64> vec64;
#define ss cout << " ";
#define nn cout << "\n";
#define ct(x) cout << x;
#define cts(x) cout << x << " ";
#define ctn(x) cout << x << "\n";
#define db(x) cout << "> " << #x << ": " << x << "\n";
#define qr queries();
void solve();
void YN(bool b){if (b){ctn("YES");}else{ctn ("NO");}};
void yn(bool b){if (b){ctn("Yes");}else{ctn ("No");}};
void queries(){int n;cin >> n;while (n--)solve();}
// // // // // // // // // // // // // // // // // // // // // // 
/*                  TEMPLATE - VANILLA                         */
// // // // // // // // // // // // // // // // // // // // // //
const int maxn = 200200;

void solve(){

    return;
}

bool comp (int a, int b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    vec arr (n);
    vec srt (n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        srt[i] = arr[i];
    }
    sort (srt.begin(), srt.end(), comp);
    // for (auto i: srt){
    //     cts(i);
    // }
    // nn;
    for (int i = 0; i < n; i++){
        bool b = 0;
        int mx = -1;
        for (int j = 0; j < n; j++){
            if (srt[j] == arr[i] && b){
                mx = srt[j];
                break;
            }
            if (srt[j] == arr[i]){
                b = 1;
                continue;
            }
            else{
                mx = srt[j];
                break;
            }
        }
        ctn(mx);
    }
    return 0;
}
