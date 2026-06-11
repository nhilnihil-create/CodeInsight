#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    string s, ss;
    cin >> s >> ss;
    bool ans = 1;

    for(unsigned i = 0; i < s.size(); ++i) {
        if(s[i] != ss[i]) 
            ans = 0;
    }

    ans ? cout << "Yes\n" : cout << "No\n";
    return 0;
}

