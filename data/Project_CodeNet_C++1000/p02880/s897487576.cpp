#include <iostream>
#include <vector>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    int n;
    cin >> n;
    vector<int> a;
    rrep(j,9) rrep(i,j) {
        a.push_back(i*j);
    }
    rep(i,45) {
        if(n == a[i]) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");

    return 0;
}
