#include <iostream>
#include <cstdio>
using namespace std;
int key;

int dfs(int n, int sum, int before) {
    int ret = 0;
    if(n == 0 && sum == key) return(1);
    if(n > 0) {
        for(int r = before; r <= 9; r++) {
            ret += dfs(n - 1, sum + r, r + 1);
        }
    }
    return(ret);

}

int main(void) {
    int n;
    while(cin >> n >> key, n + key != 0) {
        cout << dfs(n, 0, 0) << endl;
    }
    return(0);
}