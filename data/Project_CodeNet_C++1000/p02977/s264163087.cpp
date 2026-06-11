#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if((n & (n - 1)) == 0) finish("No");
    cout << "Yes\n";
    cout << "1 2\n2 3\n3 " << n + 1 << "\n" << n + 1 << " " << n + 2 << "\n" << n + 2 << " " << n + 3 << "\n";
    for(int i = 4 ; i + 1 <= n ; i += 2){
        cout << i + 1 << " " << i << "\n" << i << " 1\n1 " << n + i + 1 << "\n" << n + i + 1 << " " << n + i << "\n";
    }
    if(n % 2 == 0){
        for(int i = 2 ; i < n ; i++){
            int j = n ^ 1 ^ i;
            if(1 < j && j < n){
                cout << n << " " << i + n * (i % 2) << "\n" << j + n * (j % 2) << " " << n + n << "\n";
                break;
            }
        }
    }
}
