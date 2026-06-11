#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num, k;
        cin >> num >> k;
        vector<int> G(n, 0);
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            G[v-1] = 1;
        }
        cout << G[0];
        for (int j = 1; j < n; j++) {
            cout << " " << G[j];
        }
        cout << endl;
    }

    return 0;
}