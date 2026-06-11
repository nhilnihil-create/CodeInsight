#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector <int> previous(n+1);
    vector <int> answer(n+1, 0);
    previous[1] = -1;
    for (int i=2; i<=n; i++){
        cin >> previous[i];
        int now = previous[i];
        answer[now]++;
        
    }
    
    for (int i=1; i<=n; i++){
        cout << answer[i] << endl;
    }
}