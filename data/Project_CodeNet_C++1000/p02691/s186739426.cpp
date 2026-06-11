#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    unordered_map<int,int>mp;
    long long ttl=0ll;
    for(int i=1;i<n;i++){
        int dif=(i-v[i])-v[0];
        mp[dif]++;
        if(dif==0)
            ttl++;
    }

    for(int i=1;i<n;i++){
        int dif=(i-v[i])-v[0];
        ///mp[dif]--;
        ttl+=(long long)mp[i+v[i]-v[0]];
    }
    cout << ttl << endl;
    return 0;
}
/***
32
3 1 4 1 5 9 2 6 5 3 5 8 9 7 9 3 2 3 8 4 6 2 6 4 3 3 8 3 2 7 9 5

6
2 3 3 1 3 1
*/
