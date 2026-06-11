#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            int k = 0;
            while(((i >> k) & 1) == ((j >> k) & 1)) k++;
            cout << k + 1 << " ";
        }
        cout << endl;
    }
}
