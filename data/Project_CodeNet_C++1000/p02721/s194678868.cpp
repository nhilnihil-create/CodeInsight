#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define endl '\n'
int main()
{
    Hello
    int n, k, c;
    string s;
    cin >> n >> k >> c >> s;
    vector<int> l, r, ans;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'o'){
            l.push_back(i);
            i += c;
            if(l.size() >= k)
                break;
        }
    }
    for(int i = s.size() - 1; i >= 0; i--){
        if(s[i] == 'o'){
            r.push_back(i);
            i -= c;
            if(r.size() >= k)
                break;
        }
    }
    for(int i = 0, j = r.size() - 1; i < l.size() && j >= 0; i++, j--){
        if(l[i] == r[j])
            ans.push_back(l[i] + 1);
    }
    for(auto i : ans)
        cout << i << endl;
    return 0;
}