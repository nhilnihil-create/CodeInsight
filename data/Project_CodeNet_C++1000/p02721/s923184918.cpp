#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;

    vector<int> fast;
    for(int i=0, pre=-c-1; i<s.size(); i++)
    {
        if(i <= pre+c) continue;
        if(s.at(i) == 'o')
        {
            pre = i;
            fast.push_back(i);
        }
        if(fast.size() == k) break;
    }

    vector<int> tail(k);
    for(int i=k-1, j=s.size()-1, pre=n+c+1; j>=0; j--)
    {
        if(j >= pre-c) continue;
        if(s.at(j) == 'o')
        {
            pre = j;
            tail.at(i) = j;
            i--;
            if(i<0) break;
        }
    }

    for(int i=0; i<k; i++)
    {
        if(fast.at(i) == tail.at(i)) cout << fast.at(i) + 1 << endl;
    }

    return 0;
}