#include <iostream>
#include<cstring>

using namespace std;
char s[200007];
//WWRRWRR
int main()
{
    int n; cin >> n;
    cin >> s;
    int r=0;
    for(int i=0; i<n; i++) {
        if(s[i]=='R') r++;
    }
    int ans=r;
    for(int i=0; i<r; i++) {
        if(s[i]=='R') ans--;
    }
    cout << ans << '\n';
}
