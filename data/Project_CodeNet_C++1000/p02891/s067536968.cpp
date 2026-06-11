#include<bits/stdc++.h>
using namespace std;

int main() {
    string s; long long k;
    cin >> s >> k;
    string c = s;
    if(count(s.begin(), s.end(), s[0]) == s.size()) cout << s.size() * k / 2 << endl;
    else {
        long long res = 0;
        for (int i = 1; i < c.size(); i++)
        {
            if(c[i] == c[i-1]) {
                c[i] = '?';
                res++;
            }
        }

        if(s.front() != s.back()) cout << res * k << endl;
        else {
            long long a = 0, b = 0;
            for(int i = 0; i < s.size(); i++){
                if(s[i] != s[0]) break;
                a++;
            }
            for (int i = 0; i < s.size(); i++)
            {
                if(s[s.size()-1-i] != s[s.size()-1]) break;
                b++;
            }
            long long sub = a / 2;
            sub += b / 2;
            sub -= (a + b) / 2;
            cout << res * k - sub * (k - 1) << endl;
        }
    }
	return 0;
}
