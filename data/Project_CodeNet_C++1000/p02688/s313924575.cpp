#include<bits/stdc++.h>
using namespace std;
int n,k,d,a;
set<int>S;
int main() {
    cin >> n >> k; 
    for(int i = 0;i<k;i++){
        cin >> d;
        for(int j = 0;j<d;j++){
            cin >> a;S.insert(a);
        }
    }cout << n - S.size() << endl;
    return 0;
}
