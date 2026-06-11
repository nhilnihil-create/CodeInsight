#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int num = n;
    vector<int> ans;
    for (int i = 2; i < sqrt(n) + 1; i++)
    {
        while (num % i == 0)
        {
            num /= i;
            ans.push_back(i);
        }
    }

    cout << n << ":";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << " " << ans[i];
    }
    if(num != 1) cout << " " << num;
    cout << endl;
}
