#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long
#define pb push_back

int main()
{
    vector<pair<pair<int,int>,int> > x;
    bool flag = true;
    while (1)
    {
        int n, l;
        vector<int> vec;
        cin >> n >> l;
        if (l == 0)
        {
            break;
        }
        flag = true;
        while (flag)
        {
            vector<int> a(l);
            for (int i = l - 1; 0 <= i; i--)
            {
                a[i] = n % 10;
                n /= 10;
            }

            // maxの値を作成
            vector<int> ma(l);
            copy(a.begin(), a.end(), ma.begin());
            sort(ma.begin(), ma.end());
            reverse(ma.begin(), ma.end());

            // minの値を作成
            vector<int> mi(l);
            copy(a.begin(), a.end(), mi.begin());
            sort(mi.begin(), mi.end());
            int ma_n = 0, mi_n = 0,be_a=0;
            for (int i = 0; i < l; i++)
            {
                // cout << a[i];
                be_a += a[i] * pow(10, l - i - 1);
            }
            vec.push_back(be_a);
            for (int i = 0; i < l; i++)
            {
                // cout << ma[i];
                ma_n += ma[i] * pow(10, l - i - 1);
                mi_n += mi[i] * pow(10, l - i - 1);
            }
            // cout << endl;
            // cout << ma_n << " - " << mi_n << " = " << ma_n - mi_n << endl;
            int diff = ma_n - mi_n;
            for(int i=0; i<vec.size();i++){
                if(vec[i] == diff){
                    x.push_back(make_pair(make_pair(i,diff),vec.size()-i)); // j a i-j
                    flag = false;
                }
            }
            n = diff;
        }
    }
    for (int i = 0; i < x.size(); i++)
    {
        cout << x[i].first.first <<" "<< x[i].first.second <<" "<< x[i].second << endl;
    }
}

