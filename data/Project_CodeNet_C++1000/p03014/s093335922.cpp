#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <bitset>
#include <string>
#include <utility>
#include <queue>

using namespace std;
long long int bign = 1000000007;

int main()
{
    int h, w;
    cin >> h >> w;
    string inp;
    // vector<vector<int>> res(h*w,vector<int>(4,0));
    vector<vector<int>> ue(h, vector<int>(w, 0));
    vector<vector<int>> shita(h, vector<int>(w, 0));
    vector<vector<int>> hidari(h, vector<int>(w, 0));
    vector<vector<int>> migi(h, vector<int>(w, 0));
    vector<vector<bool>> state(h, vector<bool>(w, false));

    for (int i = 0; i < h; i++)
    {
        cin >> inp;
        for (int j = 0; j < w; j++)
        {
            if (inp.at(j) == '#')
            {
                state.at(i).at(j) = true;
            };
        }
    }
    if (!state.at(0).at(0))
    {
        ue.at(0).at(0) = 1;
        hidari.at(0).at(0) = 1;
    }
    for (int j = 1; j < w; j++)
    {
        if (!state.at(0).at(j))
        {
            hidari.at(0).at(j) = hidari.at(0).at(j - 1) + 1;
            ue.at(0).at(j) = 1;
        }
    }
    for (int i = 1; i < h; i++)
    {
        if (!state.at(i).at(0))
        {
            hidari.at(i).at(0) = 1;
            ue.at(i).at(0) = ue.at(i - 1).at(0) + 1;
        }
        for (int j = 1; j < w; j++)
        {
            if (state.at(i).at(j))
                continue;
            ue.at(i).at(j) = ue.at(i - 1).at(j) + 1;
            hidari.at(i).at(j) = hidari.at(i).at(j - 1) + 1;
        }
    }

    if (!state.at(h - 1).at(w - 1))
    {
        shita.at(h - 1).at(w - 1) = 1;
        migi.at(h - 1).at(w - 1) = 1;
    }
    for (int j = 1; j < w; j++)
    {
        if (!state.at(h - 1).at(w - 1 - j))
        {
            migi.at(h - 1).at(w - 1 - j) = migi.at(h - 1).at(w - j) + 1;
            shita.at(h - 1).at(w - 1 - j) = 1;
        }
    }
    for (int i = 1; i < h; i++)
    {
        if (!state.at(h - 1 - i).at(w - 1))
        {
            migi.at(h - 1 - i).at(w - 1) = 1;
            shita.at(h - 1 - i).at(w-1) = shita.at(h - i).at(w-1) + 1;
        }
        for (int j = 1; j < w; j++)
        {
            if (state.at(h - 1 - i).at(w - 1 - j))
                continue;
            migi.at(h - 1 - i).at(w - 1 - j) = migi.at(h - 1 - i).at(w - j) + 1;
            shita.at(h - 1 - i).at(w - 1 - j) = shita.at(h - i).at(w - 1 - j) + 1;
        }
    }

    // if(!state.at(w*(h-1)+(w-1))){res.at(w*(h-1)+(w-1)).at(2)=1;res.at(w*(h-1)+(w-1)).at(3)=1;};
    // for(int j=2;j<=w;j++){
    //     if(!state.at(w*(h-1)-(w-j))){res.at(w*(h-1)-j).at(2)=res.at(w*(h-1)+w-j+1).at(2)+1; res.at(w*(h-1)+w-j).at(3)=1;};
    // }
    // for(int i=2;i<=h;i++){
    //     if(!state.at(w*(h-i)+w-1)){res.at(w*(h-i)+w-1).at(2)=1;res.at(w*(h-i)+w-1).at(3)=res.at(w*(h-i+1)+w-1).at(3)+1 ;}
    //     for(int j=2;j<=w;j++){
    //         if(state.at(w*(h-i)+w-j))continue;
    //         res.at(w*(h-i)+w-j).at(2)=res.at(w*(h-i)+w-j+1).at(2)+1;res.at(i*w+j).at(3)=res.at(w*(h-i+1)+w-j+1).at(3)+1 ;
    //     }
    // }
    int ans = 0;
    int temp;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            
            // if (state.at(i).at(j))
            //     continue;
            temp = ue.at(i).at(j) + migi.at(i).at(j) + shita.at(i).at(j) + hidari.at(i).at(j) - 3;
            // cout << temp << ",";
            if (temp > ans)
                ans = temp;
        }
        // cout << endl;
    }
    cout <<ans<< endl;
    // for(int i=0;i<=n;i++){
    //     cout << res.at(i).first << ","<< res.at(i).second << endl;
    // }
    // cout << (res.at(n).first+res.at(n).second)%bign << endl;
    return 0;
}