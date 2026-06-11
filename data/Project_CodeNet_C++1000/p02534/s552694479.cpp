#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<pll> vpll;

void INX(){}
template<typename Head, typename... Tail>
void INX(Head&& head, Tail&&... tail)
{
    cin >> head;
    INX(forward<Tail>(tail)...);
}
void OUTX(){}
template<typename Head, typename... Tail>
void OUTX(Head&& head, Tail&&... tail)
{
    cout << head << endl;
    OUTX(forward<Tail>(tail)...);
}

#define ADD emplace_back
#define MP make_pair
#define VVEC(type) vector<vector<type>>


int main()
{
    ll K;
    INX(K);

    string tmp = "ACL";
    string result = "";
    for (ll i = 0; i < K; i++)
    {
        result.append(tmp);
    }
    OUTX(result);



    return 0;
}
