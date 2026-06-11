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
    ll N,M;
    INX(N,M);
    
    vector<set<ll>> con(N+1);
    for (ll i = 0; i < M; i++)
    {
        ll A,B;
        INX(A,B);
        con[A].insert(B);
        con[B].insert(A);
    }

    vector<set<ll>> grp;
    vector<bool> checked(N+1,false);
    for(ll i = 1; i <= N; i++)
    {
        if(checked[i])
        {
            continue;
        }
        checked[i] = true;
        
        queue<ll> q;
        for(auto x : con[i])
        {
            q.push(x);
        }

        grp.resize(grp.size() + 1);
        ll grpindex = grp.size() - 1;
        grp[grpindex].insert(i);

        while(q.size() != 0)
        {
            ll target = q.front();
            q.pop();

            if(checked[target])
            {
                continue;
            }
            checked[target] = true;
            
            for(auto x : con[target])
            {
                q.push(x);
            }

            grp[grpindex].insert(target);
        }
    }
    OUTX(grp.size() - 1);
    



    return 0;
}
