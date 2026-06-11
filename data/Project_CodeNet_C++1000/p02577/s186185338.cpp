#include<bits/stdc++.h>
using namespace std;



void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    int sum = 0;
    for (int i = 0; i < n ; i++){
        sum+= (s[i] - '0');
    }
    if(sum % 9 == 0)
        cout << "Yes";
    else
        cout << "No";
}

int main()
{

    solve();
    cout << "\n";

}


