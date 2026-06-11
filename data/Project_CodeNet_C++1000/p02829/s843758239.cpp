#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int a, b;
    cin >> a >> b;
    
    for(int i = 1; i <= 3; i++) {
        if(i != a && i != b)
            cout << i << endl;
    }
    
    
    
    
    return 0;
}
