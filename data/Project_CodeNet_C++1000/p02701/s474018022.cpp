#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define PI 3.14159265358979323846264338327950L

int n;
set<string> s;

void solve(){

    cin >> n;

    string tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;

        s.insert(tmp);
    }
    
    cout << s.size()<< endl;

}





int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

}