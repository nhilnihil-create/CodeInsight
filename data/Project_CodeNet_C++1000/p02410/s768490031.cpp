#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;


int main() {
    
    long n,m;
    cin >> n >> m;
    const long N = n;
    const long M = m;
    long mat[N][M] = {};
    long vec[M] = {};
    long ans[N] = {};
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            int p;
            cin >> p;
            mat[i][j] = p;
        }
    }
    for (int i=0;i<M;i++){
        int p;
        cin >> p;
        vec[i] = p;
    }

    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            ans[i] += mat[i][j] * vec[j];
        }
    }
    for (int i=0;i<N;i++){
        cout << ans[i] << endl;
    }


}
