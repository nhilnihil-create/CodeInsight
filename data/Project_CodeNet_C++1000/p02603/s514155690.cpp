#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n ;
    cin >> n ;
    ll arr[n];

    for(int i = 0 ; i < n; i++)
    {
        cin >> arr[i];
    }
    ll st;
    ll have=1000 , cands=0;
    for(int i = 0 ; i <n; i++)
    {
        if(i==0)
            st=arr[i];
        else
        {
            if(arr[i]<arr[i-1])
            {
                cands+=(have/st);
                have-=(cands*st);
                have+=cands*arr[i-1];
                cands=0;
                st=arr[i];
            }
        }
    }
    cands+=(have/st);
    have-=(cands*st);
    have+=cands*arr[n-1];
    cout << have << "\n";
    return 0;
}
