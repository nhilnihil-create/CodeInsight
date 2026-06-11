#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
bool triangle(int s1, int s2, int s3){
    if(s1 == s2 || s1 == s3 || s2 == s3) return false;
    return((s1 + s2 > s3) &&
           (s1 + s3 > s2) &&
           (s2 + s3 > s1));
}
int main(){
    Hello
    int n, ans = 0;
    cin >> n;
    int l[n];
    for(int i = 0; i < n; i++)
        cin >> l[i];
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            for(int k = j + 1; k < n; k++)
                if(triangle(l[i], l[j], l[k]))
                    ans++;
    cout << ans;
    return 0;
}