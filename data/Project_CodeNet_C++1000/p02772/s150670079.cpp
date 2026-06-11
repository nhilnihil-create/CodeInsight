#include <bits/stdc++.h>
using namespace std;
int main(){
        int n; cin >> n;
        bool d = true;
        for (int x = 0; x < n; ++x){
            int a; cin >> a;
            if (a % 2 == 0){
                if (a % 3 != 0 && a % 5 != 0){
                    d = false;
                }
            }
        }
        if (d) cout << "APPROVED" << endl;
        else cout << "DENIED" << endl;
    return 0;
}

