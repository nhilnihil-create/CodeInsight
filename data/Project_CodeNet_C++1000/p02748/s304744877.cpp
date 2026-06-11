#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define rep(i,n) for(int i=0; i < n; i++)
using ll =  long long;
using namespace std;

int main()
{
    int type_ref, type_mic, type_dis;    //冷蔵庫の種類 電子レンジの種類 割引券の種類
    cin >> type_ref >> type_mic >> type_dis;

    //冷蔵庫の種類別の値段を取得し、最も値段の安いものを探す
    vector<int> price_ref(type_ref);
    int mp_ref = 100100;
    rep(i, type_ref)
    {
        cin >> price_ref[i];
        mp_ref = min(mp_ref, price_ref[i]);
    }

    //電子レンジの種類別の値段を取得
    vector<int> price_mic(type_mic);
    int mp_mic = 100100;
    rep(i, type_mic)
    {
        cin >> price_mic[i];
        mp_mic = min(mp_mic, price_mic[i]);
    }

    //割引券なしでの最小金額
    int min_amount = mp_ref + mp_mic;

    //割引券(効果がないものは除外)を使いながら最小金額を探す
    rep(i, type_dis)
    {
        int target_ref, target_mic, discount;
        cin >> target_ref >> target_mic >> discount;
        
        //対象外の場合飛ばす
        if (target_ref > type_ref || target_mic > type_mic) continue;
        
        int _min_amount = price_ref[target_ref-1] + price_mic[target_mic-1] - discount;
        min_amount = min(min_amount, _min_amount);
    }

    cout << min_amount << endl;
    return 0;
}