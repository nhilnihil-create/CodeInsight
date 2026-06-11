#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    string s1, s2;
    s1 = s; s2 = s;

    int cnt1 = 0, cnt2 = 0;
    int index1 = 0, index2 = 0;
    while(cnt1 < k && index1 < n){
        if(s1[index1] == 'L') {
            s1[index1] = 'R';
            while(index1 < n){
                if(s1[++index1] == 'L') s1[index1] = 'R';
                else break;
            }
            cnt1++;
        }
        else index1++;
    }

    while(cnt2 < k && index2 < n){
        if(s2[index2] == 'R') {
            s2[index2] = 'L';
            while(index2 < n){
                if(s2[++index2] == 'R') s2[index2] = 'L';
                else break;
            }
            cnt2++;
        }
        else index2++;
    }

    int ans1=0, ans2=0, ans=0;
    rep(i,n-1){
        if(s1[i] == s1[i+1]) ans1++;
        if(s2[i] == s2[i+1]) ans2++;
    }

    ans = max(ans1, ans2);

    cout << ans << endl;

    return 0;
}
