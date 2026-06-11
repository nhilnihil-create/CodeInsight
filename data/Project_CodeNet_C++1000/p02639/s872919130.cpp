#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;
typedef int64_t ll;

int main() {
    for (int i = 0; i < 5; i++){
        int a;
        cin >> a;
        if (a == 0){
            cout << i + 1 << endl;
            return 0;
        }
    }
}