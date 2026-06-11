#include <bits/stdc++.h>
using namespace std;


int main (){
    int H, W, M;
    cin >> H >> W >> M;
    //vector<vector<bool> > m(H,vector<bool>(W,0));//爆破対象のある座標を
    map<pair<int, int>, bool> m;
    pair<int, int> temppair;
    vector<int> hx(H,0);//ｈ座標にある爆破対象の個数を
    vector<int> wy(W,0);//ｗ座標にある爆破対象の個数を
    int h, w;//一時的に置く場所
    for(int i = 0; i < M; i++) {
        cin >> h >> w;
        //m.at(h - 1).at(w - 1) = 1;//それぞれ，0から初め一個少なく終わる
        temppair = make_pair(h - 1,w - 1);
        m[temppair] = 1;
        hx.at(h - 1)++;//任意のH座標にある爆破対象数え上げる
        wy.at(w - 1)++;//任意のW座標にある爆破対象数え上げる
    }
    int hh = 0;
    int ww = 0;
    hh = *max_element(hx.begin(), hx.end());//同じ行にある爆破対象の最大個を
    ww = *max_element(wy.begin(), wy.end());//同じ列にある爆破対象の最大個を
    
    //cout << h + w << endl;
    vector<int> hl;//最大個数の爆破対象を持つ行をリストアップ
    int hln = 0;
    vector<int> wl;//最大個数の爆破対象を持つ列をリストアップ
    int wln = 0;
    for(int i = 0; i < H; i++) {
        if(hh == hx.at(i)) {
            hl.push_back(i);
            //cout << i << endl;
        }
    }
    for(int i = 0; i < W; i++) {
        if(ww == wy.at(i)) {
            wl.push_back(i);
            //cout << i << endl;
        }
    }
    int ans = hh + ww;//交差地点，つまり爆破する地点に爆破対象がある場合を考慮せず，とりあえず最大の爆破個数を答えとする

    hln = hl.size();//最大個数の爆破対象を持つ行の個数を
    wln = wl.size();//最大個数の爆破対象を持つ列の個数を


    for(int h = 0; h < hln; h++) {
        for(int w = 0; w < wln; w++) {
            //if(!m.at(hl.at(h)).at(wl.at(w))) {
            temppair = make_pair(hl.at(h),wl.at(w));
            if(!m.count(temppair)) {
                cout << ans << endl;//交差地点，つまり爆破スべき地点に爆破対象がない場合を見つけ出す
                return 0;
            }
        }
    }
    cout << ans - 1 << endl;//交差地点に爆破対象がない場合を見つけられない買ったため，重複して数えられた部分を減算する    
}