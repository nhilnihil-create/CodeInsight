#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        string s;
        cin >> s;
        for(char c: s){
                if(c == '?'){
                        cout << 'D';
                } else{
                        cout << c;
                }
        }
}
