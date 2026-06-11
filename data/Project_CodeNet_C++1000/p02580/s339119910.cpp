#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(void)
{
    int H, W, M;
    cin >> H >> W >> M;

    vector<int> hPl(H, 0);
    vector<int> wPl(W, 0);
    set<pii> st;

    for (int i = 0; i < M; i++)
    {
        int h, w;
        cin >> h >> w;
        h--; w--;

        hPl[h]++;
        wPl[w]++;
        st.insert({h,w});
    }
    

    int hmax = *max_element(hPl.begin(), hPl.end());
    int wmax = *max_element(wPl.begin(), wPl.end());

    vector<int> hmaxId, wmaxId;

    for (int i = 0; i < H; i++)
    {
        if(hPl[i] == hmax){
            hmaxId.push_back(i);
        }
    }

    for (int i = 0; i < W; i++)
    {
        if(wPl[i] == wmax){
            wmaxId.push_back(i);
        }
    }
    
    bool bombOverlap = true;

    int ans =  hmax + wmax;
    for (auto hid : hmaxId)
    {
        for (auto wid : wmaxId)
        {
            if(st.find({hid,wid}) == st.end()){
                bombOverlap = false;
                cout << ans << endl;
                return 0;
            }
        }
    }

    ans -= 1;

    cout << ans << endl;

    return 0;
}
