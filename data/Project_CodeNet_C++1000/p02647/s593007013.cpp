#include<cmath>
#include<iostream>
#include<vector>

using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int ki = 0; ki < k; ki++){
        vector<int> b(n+1);
        for(int i = 0; i < n; i++){
            int l = max(0, i-a[i]);
            int r = min(i+a[i]+1, n);
            b[l]++; b[r]--;
        }
        for(int i = 0; i < n; i++) b[i+1] += b[i];
        b.pop_back();
        if(a == b) break;
        a = b;
    }
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

