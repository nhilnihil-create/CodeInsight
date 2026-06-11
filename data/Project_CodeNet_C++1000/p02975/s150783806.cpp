#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
using namespace std;
 
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    int tmp = 0;
    rep(i, 0, N) {
        cin >> A[i];
        tmp = tmp ^ A[i];
    }
    if (tmp){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    
    return 0;
}