#include<bits/stdc++.h>

using namespace std;
using ll = long long;

bool res = true;
int n, k, c;

vector<int> f(string s) {
    vector<int> ret;
    for(int i = 0; i < n; i++) {
        while(s[i] == 'x' && i < n)i++;
        if(s[i] == 'o')ret.push_back(i);
        for(int j = 0; j < c; j++)i++;
    }
    if((int)ret.size() > k)res = false;
    return ret;
}


int main()
{
    cin >> n >> k >> c;
    string s; cin >> s;

    vector<int> fr = f(s);
    if(!res)return 0;
    reverse(s.begin(), s.end());
    vector<int> bc = f(s);
    {
        int m = bc.size();
        for(int i = 0; i < m; i++) {
            bc[i] = n - bc[i] - 1;
        }
    }

    sort(bc.begin(), bc.end());
    
    for(auto i : bc) {
        if(binary_search(fr.begin(), fr.end(), i)) {
            cout << i + 1 << endl;
        }
    }

}