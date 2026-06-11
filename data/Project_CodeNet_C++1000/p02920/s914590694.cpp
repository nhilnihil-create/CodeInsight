#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)
#define vecrep(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)

class removeingarray
{
    vector<int> *_s;
    vector<pair<int, int>> _list;
    public:
        removeingarray(vector<int> &s)
        {
            _s = &s;
            int index = 0;
            _list.resize(s.size());
            while( index < s.size() )
            {
                int c = s[index];
                int i = 1;
                while(c == s[index + i]) 
                {
                    _list[index + i].first = index;
                    _list[index + i].second = -1;
                    i++;
                }
                _list[index].first = index + i;
                if( _list[index].first >= s.size() ) _list[index].first = -1;
                _list[index].second = i;
                index += i;
            }
        }

        int removenext(int index)
        {
            if( _list[index].second < 0 ) index = _list[index].first;
            auto ret = getnextsub(_list[index].first);
            _list[index].first = ret.second;
            return ret.first;
        }

        int removeat(int index)
        {
            auto ret = getnextsub(index);
            return ret.first;
        }

        pair<int, int> getnextsub(int index)
        {
            if( index >= _s->size() || index < 0 ) return make_pair(-1, -1);
            if( _list[index].second == 0 )
            {
                auto ret = getnextsub(_list[index].first);
                _list[index].first = ret.second;
                return ret;
            }
            else
            {
                _list[index].second--;
                if( _list[index].second == 0 ) return make_pair( index, _list[index].first );
                return make_pair(index, index);
            }
        }
};

bool getans()
{
    int n; cin >> n;
    int n2 = (1 << n);
    vector<int> s(n2);
    rep(i, n2) cin >> s[i];
    sort(s.begin(), s.end(), greater<int>());
    removeingarray ra(s);
    vector<int> slime;
    slime.push_back(ra.removeat(0));
    rep(i, n)
    {
        int num = slime.size();
        rep(j, num)
        {
            int ret = ra.removenext(slime[j]);
            if( ret < 0 ) return false;
            slime.push_back(ret);
        }
    }
    return true;
}

int main()
{
    if(getans())
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;    
}