#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

typedef long long ll;

const int MAX_N = 300005;

int n, A[MAX_N];
vector<int> V;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        A[a]++;
    }
    
    int dod = 0;
    for(int i = 1; i <= n; i++) {
        if(A[i] > 0) {
            V.push_back(A[i]);
            dod++;
        }
    }
    sort(V.begin(), V.end());
    
    int suma = n;
    for(int i = 1; i <= n; i++) {

        bool go = true;
        while(go) {
            go = false;
            for(int j = dod - 1; j >= 0; j--) {
                if(V[j] <= suma / i) {
                    break;
                } 
                while(V[j] > suma / i) {
                    V[j]--;
                    suma--;
                    go = true;
                }
            }
        }
        if(i > dod) cout << 0 << endl;
        else cout << suma / i << endl;
    }

    return 0;
}
