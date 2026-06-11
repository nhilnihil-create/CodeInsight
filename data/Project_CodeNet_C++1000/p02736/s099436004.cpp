#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000006
#define LOG_N 20

int twos[MAX_N] ,lg2[MAX_N];

int main()
{
    for(int i=0; i<LOG_N; i++)
        lg2[1<<i] = i;
    for(int i=1; i<MAX_N; i++)
        twos[i] += twos[i-1] + lg2[i&-i];

    int n;
    string s;
    cin >> n >> s;

    if(count(s.begin() ,s.end() ,'2') == 0){
        bool on = 0;
        for(int i=0; i<n; i++)
            on ^= (s[i] == '3')&!(twos[n-1]-twos[n-i-1]-twos[i]);
        cout << 2*on << endl;
    }
    else{
        bool on = 0;
        for(int i=0; i<n; i++)
            on ^= !(s[i]&1)&!(twos[n-1]-twos[n-i-1]-twos[i]);
        cout << on << endl;
    }
}
