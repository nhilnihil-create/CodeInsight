#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++)
        cin >> h[i];
    bool ans = true;
    for(int i = 0; i < n - 1; i++){
        if(h[i] == h[i + 1])
            continue;
        else if(h[i] < h[i + 1])
            h[i + 1]--;
        else ans = false;
    }
    if(ans)
        cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}