#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define ALL(A) A.begin(),A.end()

void ALLIN1_NUMBER(vector<ll>& V)
{
    for(auto& x : V)
    {
        cin >> x;
    }
}

void ALLOUT_NUMBER(vector<ll> V)
{
    ll N = V.size();
    for(ll i=0;i<N;i++)
    {
        cout << V[i];
        if(i<N-1) cout << ' ';
    }
    cout << endl;
}

template<class T>
void OUT0(T N)
{
    cout << N << endl;
}

static const double pi = acos(-1.0);

double Cos(double D)
{
    return cos(pi/180 * D);
}

class Magic
{
    public:
    ll A,B;
};

void Sort_Magics(vector<Magic>& Magics)
{
    sort(ALL(Magics),
    [](Magic& A, Magic& B)
    {
        return (A.A==B.A) ? (A.B < B.B) : (A.A > B.A);
    });
}

void ALLIN_MAGICS(ll N, vector<Magic>& Magics)
{
    vector<Magic> magics(N);
    for(ll i=0;i<N;i++)
    {
        cin >> magics[i].A >> magics[i].B;
    }
    
    map<ll,ll> magics_map;
    for(auto x : magics)
    {
        if(magics_map[x.A]==0)
        {
            magics_map[x.A] = x.B;
        }
        else
        {
            magics_map[x.A] = min(magics_map[x.A],x.B);
        }
    }

    for(auto x : magics_map)
    {
        Magics.push_back({x.first,x.second});
    }
}

void ALLOUT_MAGICS(vector<Magic> Magics)
{
    for(auto x : Magics)
    {
        cout << x.A << ' ' << x.B << endl;
    }
}

ll DP(ll H, vector<Magic> Magics)
{
    vector<ll> dp(H+1,1e9);
    dp[0] = 0;
    for(ll i=0;i<H;i++)
    {
        if(dp[i]!=1e9)
        {
            for(auto x : Magics)
            {
                dp[min(H,i+x.A)] = min(dp[min(H,i+x.A)],dp[i]+x.B);
            }
        }
    }
    return dp[H];
}

int main()
{
    ll H,N;
    cin >> H >> N;

    vector<Magic> Magics;
    ALLIN_MAGICS(N,Magics);

    OUT0(DP(H,Magics));

    return 0;
}