#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


bool chk_pal (string s)
{
ll l = s.size();
for (int i=0; i<l/2; i++){
    if (s[i] != s[l-i-1]){return false;}
}
return true;

}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    string s, s1, s2;
    cin >> s;
    ll len = s.size();
    ll len1 = (len - 1) / 2;
    ll len2 = (len + 3) / 2;
    for (int i=0; i<len1; i++){
        s1 += s[i];
    }
    for (int i=len2-1; i<len; i++){
        s2 += s[i];
    }
    if ((chk_pal(s1)) && (chk_pal(s2)) && (chk_pal(s))){cout << "Yes" << endl;}
    else {cout << "No" << endl;}

    return 0;
}
