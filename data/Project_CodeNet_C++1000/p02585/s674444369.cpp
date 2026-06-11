#include <string>
#include <iostream>
#include <stack>
#include <queue> // priority_queue も入ってる
#include <set>   // 要素数は size() で取得 multisetもある
#include <map>
#include <array> // sizeはコンパイル時定数で固定
#include <vector>
#include <numeric>   // accumulate, gcd
#include <algorithm> // count_ifに必要
#include <iomanip>   // cout << setprecision(15) << x で小数の出力精度を指定
#include <tuple>
#include <utility> //pair
#include <cmath>
#include <random>

using namespace std;
// 問題が起こるまでintは使用禁止2020-04-13
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)

template <class InputIterator, class T>
bool contains_itr(InputIterator iterator, const T &value)
{
    if (find(iterator.begin(), iterator.end(), value) == iterator.end())
        return false;
    else
        return true;
}

template <class T>
bool contains_set(set<T> st, const T &value)
{
    if (st.find(value) == st.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <class InputIterator>
auto sum(InputIterator iterator)
{
    return accumulate(iterator.begin(), iterator.end(), 0);
}

// endは排他的(exclusive)なので注意
vector<ll> range(ll begin, ll end)
{
    vector<ll> result;
    for (ll i = begin; i < end; ++i)
    {
        result.push_back(i);
    }
    return result;
}

random_device seed_gen;
mt19937 engine(seed_gen());
// 0, 1, 2 のどれかが得られる一様分布
// uniform_int_distribution<> dist(0, 2);
// cout << dist(engine) << endl;
// みたいに、先に確率分布を宣言して、そこにengineを与えて使う。

// =========ここまでテンプレ============

// このコードは、ABC179のE問題に提出したもの
// https://atcoder.jp/contests/abc179/tasks/abc179_e

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n);
    vector<ll> c(n);
    rep(i, n)
    {
        ll tempP;
        cin >> tempP;
        --tempP;
        p[i] = tempP;
    }
    rep(i, n) cin >> c[i];

    // TODO: 到達しうる場所のインデックスの最大値+1(通常は到達しうる場所の数)
    ll maxPlace = n;

    // TODO: 最大移動可能回数
    ll maxStep = k;

    vector<bool> didVisit(maxPlace, false);
    vector<ll> stepAt(maxPlace);
    vector<ll> scoreAt(maxPlace);
    ll greatest = LLONG_MIN;
    for (ll i = 0; i < n; ++i)
    {
        // if (didVisit[i])
        //     continue;
        didVisit = vector<bool>(maxPlace, false);
        stepAt = vector<ll>(maxPlace);
        scoreAt = vector<ll>(maxPlace);

        // TODO: スタート地点
        ll startAt = i;
        // TODO: スタート地点に移動後のスコア
        ll scoreOfStart = 0;

        // スタート地点への移動
        ll nowAt = startAt;
        ll step = 0;
        ll score = scoreOfStart;

        // ここでは、歩き過ぎないようチェック
        // while文に入ると移動するので、まだ移動できる場合にだけtrue
        while (step < maxStep)
        {
            // 判定(先にステップ続行を書く。elseでループ部分をまとめて処理してstepとscoreを一気に増やす。)
            if (didVisit[nowAt] == false)
            {
                // 記録(didVisitとstepAtとscoreAtを更新)
                didVisit[nowAt] = true;
                stepAt[nowAt] = step;
                scoreAt[nowAt] = score;

                // 移動(現在地を変え、歩数とスコアを移動後のものに更新)
                // TODO: スコアも移動先も問題によって違う！書き換えて！
                nowAt = p[nowAt];
                score += c[nowAt];
                greatest = max(greatest, score);
                step++;
            }
            else
            {
                // この瞬間、「ループのスタート地点に移動済み」で記録上書き前
                ll periodStep = step - stepAt[nowAt];
                ll periodScore = score - scoreAt[nowAt];
                // あと一歩も動かずに終わることがないようにする。最後1ループちょうど残ってても自力で歩く。
                // 1引いてから周期で割ればいいね
                ll remainingLoops = (maxStep - step - 1) / periodStep;
                step += remainingLoops * periodStep;
                score += remainingLoops * periodScore;
                // 訪問済みフラグを全て消します。
                didVisit = vector<bool>(maxPlace, false);
                // あとは通常処理に戻って、歩数の限界まで歩きます。
                if (periodScore <= 0)
                    break;
            }
        }
    }

    // TODO: 出力するものはこれでよい？
    cout << greatest << endl;
    return 0;
}

// ABC179後の2020-09-20に作ったものです