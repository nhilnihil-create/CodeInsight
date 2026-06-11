#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    stack<int> R;
    queue<int> W;
    string s;
    cin>>s;
    int l = s.length();
    for (int i=0; i<l; i++) 
        if (s[i] == 'R') R.push(i);
        else W.push(i);
    int res = 0;
    while(!R.empty() && !W.empty())
    {
        int a = R.top(), b = W.front();
        if (a > b) {
            //cout << a << " " << b << '\n';
            swap(s[a], s[b]); res++;
        }
        else break;
        R.pop(); W.pop();
        
    }
    cout << res << '\n';
    return 0;
}