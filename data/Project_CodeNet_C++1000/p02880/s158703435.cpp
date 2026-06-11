#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int n;
    cin >> n;
    for(int i = 1; i < 10; i++) {
        for(int j = 1; j < 10; j++) {
            if(i*j == n) {
                cout << "Yes" << endl;
                return 0;
            } 
        }
    }

    cout << "No" << endl;

    return 0;
}