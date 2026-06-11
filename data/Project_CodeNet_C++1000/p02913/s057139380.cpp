#include <iostream>
#include <iomanip>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <map>
#include <climits>
#include <bitset>

#define ll long long
const ll MOD = 1e9 + 7;
const ll INF = 1 << 29;

std::vector<int> ZAlgorithm(const std::string& S)
{
    std::vector<int> Z(S.size());
    Z[0] = S.size();

    // 現在の探索位置
    auto idx = 1;

    // 一致した文字数
    auto matched = 0;

    while (idx < S.size())
    {
        // S[i]の位置から何文字がSの共通接頭辞か
        while (idx + matched < S.size() && S[matched] == S[idx + matched])
            matched++;

        Z[idx] = matched;

        if (matched == 0)
        {
            idx++;
            continue;
        }

        // 一致した分だけ既存のZ値をコピーできる
        // ただし k + Z[k] が 一致した文字数 j 以上になると Z[i+k] = Z[k] が成り立たなくなる可能性がある
        auto k = 1;
        while (k + Z[k] < matched)
        {
            Z[idx + k] = Z[k];
            k++;
        }

        // コピーした分を飛ばす
        idx += k;
        matched -= k;
    }

//    for (auto z : Z)
//        std::cout << z << std::endl;

    return Z;
}

int main()
{
    std::ios::sync_with_stdio(false);

    ll N;
    std::string S;
    std::cin >> N >> S;

    auto result = 0;
    for (auto i=0; i<N; ++i)
    {
        auto subStr = S.substr(i, N - i);
        auto zResult = ZAlgorithm(subStr);

        //j文字目までの最長共通接頭辞
        for (auto j=0; j < subStr.size(); ++j)
            result = std::max(result, std::min(j, zResult[j]));
    }

    std::cout << result << std::endl;
}
