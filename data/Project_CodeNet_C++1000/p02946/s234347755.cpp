#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int K,X;
    cin >> K >> X;

    vector<int> ans;
    int step = K-1;
    ans.push_back(X);

    for(int i=1;i<=step;i++) {
        ans.push_back(X+i);
        ans.push_back(X-i);
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
