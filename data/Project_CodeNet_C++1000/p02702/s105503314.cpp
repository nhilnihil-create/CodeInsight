#include <bits/stdc++.h>
using namespace std;

vector <int> mods(2020) ,temp(2020);

int main()
{
    string s;
    cin >> s;
    mods[0] = 1;
    int all = 0 ,ans = 0;
    for(int i=0; i<s.size(); i++){
        for(int m=0; m<2020; m++)
            temp[m] = 0;
        for(int m=0; m<2020; m++)
            temp[m*10%2019] += mods[m];
        swap(mods ,temp);
        all *= 10;
        all += s[i]-'0';
        all %= 2019;
        ans += mods[all];
        mods[all]++;
    }
    printf("%d\n",ans);
}
