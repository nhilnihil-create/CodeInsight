#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main()
{
    Hello
    int n;
    string s;
    cin >> n >> s;
    for(int i = 0; i < s.size(); i++){
        int cntr = n;
        char ch = s[i];
        while(cntr--){
            ch++;
            if(ch > 'Z')
                ch = 'A';
        }
        cout << ch;
    }
    return 0;
}