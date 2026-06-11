#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int l,r;
    cin >> l >> r;
    
    if(l%2019==0 || r%2019==0 || l/2019!=r/2019){
        cout << 0 << endl;
        return 0;
    }

    vector<int> a;
    int p=l%2019,q=r%2019;

    for(int i = p; i < q; i++){
       for(int j = i+1; j <=q; j++){
            int x=i*j;
            x %= 2019;
            a.push_back(x);
       } 
    }
    sort(a.begin(),a.end());
    cout << a[0] << endl;
    return 0;
}