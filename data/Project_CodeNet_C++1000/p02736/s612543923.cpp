#include <bits/stdc++.h>
using namespace std;

int main()
{
    auto twos = [](int x){
        int ret = 0;
        for(int i=1; i<20; i++)
            ret += x/(1<<i);
        return ret;
    };

    int n;
    string s;
    cin >> n >> s;

    if(count(s.begin() ,s.end() ,'2') == 0){
        bool on = 0;
        for(int i=0; i<n; i++)
            on ^= (s[i] == '3')&!(twos(n-1)-twos(n-i-1)-twos(i));
        cout << 2*on << endl;
    }
    else{
        bool on = 0;
        for(int i=0; i<n; i++)
            on ^= !(s[i]&1)&!(twos(n-1)-twos(n-i-1)-twos(i));
        cout << on << endl;
    }
}
