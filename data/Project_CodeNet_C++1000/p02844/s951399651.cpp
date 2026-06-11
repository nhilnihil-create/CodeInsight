#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 0; i <= 999; i++)
    {
       int a = i / 100;
       int b = (i/10) % 10;
       int c = i % 10;
       int pa,pb,pc;
       pa = -1,pb = -1, pc = -1;
       int j = 0;
       while(pa == -1)
       {
           if(j >= s.length()) break;
           if(a == s[j] - '0') pa = j;
           j++;
       }
       while(pb == -1)
       {
           if(j >= s.length()) break;
           if(b == s[j] - '0') pb = j;
           j++;
       }
       while(pc == -1)
       {
           if(j >= s.length()) break;
           if(c == s[j] - '0') pc = j;
           j++;
       }
       if(pa != -1 && pb != -1 && pc != -1) ans++;
    }
    cout << ans << endl;
}
