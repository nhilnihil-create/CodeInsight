#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//#define endl '\n'
#define ll long long
int main()
{
    Hello
    int n;
    ll k;
    cin >> n >> k;
    int arr[n + 5];
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    int lst = -1, cur = 1;
    vector<int> all, first, second;
    map<int, bool> vis;
    while(true){
        if(vis[cur] == true){
            lst = cur;
            break;
        }
        else{
            vis[cur] = true;
            all.push_back(cur);
            cur = arr[cur];
        }
    }
    for(int i = 0; i < all.size(); i++){
        if(all[i] == lst){
            second.push_back(all[i]);
            continue;
        }
        if(second.size()) second.push_back(all[i]);
        else first.push_back(all[i]);
    }
    if(k < first.size()) cout << first[k];
    else{
        k -= first.size();
        cout << second[k % ((int)(second.size()))];
    }
    return 0;
}