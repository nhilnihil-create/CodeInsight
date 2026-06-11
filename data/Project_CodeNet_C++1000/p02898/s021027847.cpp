#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &i : a)cin >> i;
    cout << count_if(a.begin(), a.end(), [&](int a){return a >= k;}) << endl;
}