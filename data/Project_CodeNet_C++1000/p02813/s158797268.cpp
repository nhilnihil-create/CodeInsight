#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    int n;
    cin >> n;
    vector<int>p(n),q(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) cin >> q[i];
    if(p == q) 
    {
        cout << 0 << endl;
        return 0;
    }
    int k = 0;
    int r;
    while(1)
    {
        if(p[k] == q[k]) k++;
        if(p[k] > q[k]) 
        {
            r = 0; //pの方が辞書順では大きい
            break;
        }
        if(p[k] < q[k]) 
        {
            r = 1; //qの方が辞書順では大きい
            break;
        }
    }
    int ans = 0;
    if(r == 0)
    {
        do
        {
            bool f = true;
            for(int i = 0; i < n; i++) if(p[i] != q[i]) f = false;
            if(!f) ans++;
            else break;
        }while(next_permutation(q.begin(),q.end()));
    }
    if(r == 1)
    {
        do
        {
            bool f = true;
            for(int i = 0; i < n; i++) if(p[i] != q[i]) f = false;
            if(!f) ans++;
            else break;
        }while(next_permutation(p.begin(),p.end()));
    }
    cout << ans << endl;
}