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

ll happiness_counter()
{
    string s;
    cin >> s;

    ll N = s.size();

    ll ret = 0;

    for(ll i=0;i<N;i++)
    {
        if(s[i]=='L')
        {
            if(i>0)
            {
                if(s[i-1]=='L')
                {
                    ret++;
                }
            }
        }
        else
        {
            if(i<N-1)
            {
                if(s[i+1]=='R')
                {
                    ret++;
                }
            }
        }
    }
    return ret;
}

ll Ans(ll happiness_number, ll N, ll K)
{
    return min(N-1,happiness_number + 2 * K);
}

int main()
{
    ll N,K;
    cin >> N >> K;

    OUT0(Ans(happiness_counter(),N,K));

    return 0;
}