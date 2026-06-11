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

void ALLOUT_NUMBERS(vector<ll> V)
{
    for(auto x : V)
    {
        cout << x << ' ';
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

class numbers
{
    public:
    ll a,b,c,d;    
};

void ALLIN_POINTS(vector<numbers>& points)
{
    for(auto& x : points)
    {
        cin >> x.a >> x.b >> x.c >> x.d;
    }
}

void ALLOUT_POINTS(vector<numbers> points)
{
    for(auto x : points)
    {
        cout << x.a << ' ' << x.b << ' ' << x.c << ' ' << x.d << endl;
    }
}

void CREATE_AND_PUSH_ANY_NUMBERS(ll N, ll M, ll Q, ll depth, vector<ll> compare_numbers, vector<numbers>& points, ll& score)
{
    if(depth==N)
    {
        ll score_compare = 0;
        for(auto x : points)
        {
            if(compare_numbers[x.b-1]-compare_numbers[x.a-1]==x.c)
            {
                score_compare += x.d;
            }
        }
        score = max(score,score_compare);
    }
    else
    {
        ll Nsize = compare_numbers.size();
        for(ll i=compare_numbers[Nsize-1]; i<=M; i++)
        {
            vector<ll> numbers_copy = compare_numbers;
            numbers_copy.push_back(i);
            CREATE_AND_PUSH_ANY_NUMBERS(N,M,Q,depth+1,numbers_copy,points,score);
        }
    }
}

ll OUT_ANY_NUMBERS(ll N, ll M, ll Q, vector<numbers> points)
{
    vector<ll> numbers = {0};
    ll score = 0;
    for(ll i=1;i<=M;i++)
    {
        numbers[0] = i;
        CREATE_AND_PUSH_ANY_NUMBERS(N,M,Q,1,numbers,points,score);
    }
    return score;
}

int main()
{
    ll N,M,Q;
    cin >> N >> M >> Q;

    vector<numbers> points(Q);
    ALLIN_POINTS(points);

    OUT0(OUT_ANY_NUMBERS(N,M,Q,points));

    return 0;
}