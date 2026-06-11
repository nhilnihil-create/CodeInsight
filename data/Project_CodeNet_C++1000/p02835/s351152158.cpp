#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
typedef long long ll;



int main() {
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    
    int sum = a1 + a2 + a3;
    
    if(sum > 21)
        cout << "bust" << endl;
    else
        cout << "win" << endl;
    
    
    
    return 0;
}
