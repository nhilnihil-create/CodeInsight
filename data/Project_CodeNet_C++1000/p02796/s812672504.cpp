#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> arm;
    vector<int> L(n);
    vector<int> R(n);
    for(int i = 0; i < n; ++i)
    {
        int x,l;
        cin >> x >> l;
        arm.push_back(make_pair(x+l,i));
        arm.push_back(make_pair(x-l,i));
        L[i] = x-l;
        R[i] = x+l;
    }
    sort(arm.begin(), arm.end());

    int ans = 0;
    vector<int> cur;
    vector<int> tmpCur;
    vector<bool> checker(n);
    vector<bool> outer(n);
    for(pair<int,int> p : arm)
    {
        int id = p.second;
        int val = p.first;
        if(outer[id])
        {
            continue;
        }
        else if(checker[id])
        {
            ++ans;
            //cout << L[id] << " " << id << " " << R[id] << endl;
            tmpCur.clear();
            for(int c : cur)
            {
                if(L[c] == val)
                {
                    tmpCur.push_back(c);
                    continue;
                }
                outer[c] = true;
            }
            cur.clear();
            cur = tmpCur;
        }
        else
        {
            checker[id] = true;
            cur.push_back(id);
        }
    }
    cout << ans << endl;
}