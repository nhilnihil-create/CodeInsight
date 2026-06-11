#include <bits/stdc++.h>
#define endl '\n'
#define uset unordered_set
#define umap unordered_map
#define all(var) var.begin(), var.end()
#define input freopen("input", "r", stdin)
#define output freopen("output", "w", stdout)
#define Fast ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL)
typedef long long ll;
using namespace std;

int dr[] = {0, 0, -1, +1, -1, -1, +1, +1};
int dc[] = {-1, +1, 0, 0, -1, +1, -1, +1};

int main(){
    int n; cin >> n;
    int arr[n];
    auto isTri = [](int a, int b, int c){
        return a+b > c && a+c > b && b+c > a;
    };
    for(int &i: arr) cin >> i;
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] == arr[j]) continue;
            for(int k = j+1; k < n; k++){
                if(arr[i] == arr[k] || arr[j] == arr[k]) continue;
                if(isTri(arr[i], arr[j], arr[k]))
                    ans++;
            }
        }
    }
    cout << ans << endl;
}

