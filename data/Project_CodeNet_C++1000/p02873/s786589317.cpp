#include<bits/stdc++.h>
using namespace std;

#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;
typedef pair<lli, lli> pii;


int main()
{
    string s;
    cin >> s;
    int n = s.size();
    lli ans = 0, now = 0LL;
    for(int i=0; i<n;){
        lli cnt = 0;
        if(s[i] == '<'){
            while(i < n && s[i]  == '<'){
                cnt++;
                i++;
            }
            ans += (now+cnt)*(now+cnt+1)/2 - (now)*(now-1)/2;
            now = now+cnt;

        }
        else{
            while(i < n && s[i]  == '>'){
                cnt++;
                i++;
            }
            if(now >= cnt){
                ans += (cnt)*(cnt-1)/2;
                now  = 0;
            }
            else{
                ans -= now;
                ans += (cnt)*(cnt+1)/2;
                now = 0;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
