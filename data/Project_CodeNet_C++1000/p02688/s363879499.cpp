#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;

int main(void){
    int n, k;
    cin >> n >> k;
    vi s(n, 1);
    for(int i=0; i<k; i++){
        int d;
        cin >> d;
        for(int j=0; j<d; j++){
            int a;
            cin >> a;
            s[a-1] = 0;
        }
    }
    int cnt = 0;
    for(int &x : s) cnt += x;
    cout << cnt << '\n';
    return 0;
}