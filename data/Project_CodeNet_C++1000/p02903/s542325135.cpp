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

void ALLOUT2_WITHOUT_SPACE(vector<vector<ll>> V)
{
    ll Vsize = V.size();
    ll Visize = V[0].size();
    for(ll i=0;i<Vsize;i++)
    {
        for(ll j=0;j<Visize;j++)
        {
            cout << V[i][j];
        }
        cout << endl;
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

pair<ll,ll> Graph(ll H, ll W, ll A, ll B)
{
    for(ll i=H;i>=0;i--)
    {
        for(ll j=W;j>=0;j--)
        {
            if(A*H + (W-2*A)*i == B*W + (H-2*B)*j)
            {
                return make_pair(i,j);
            }
        }
    }
    return make_pair(-1,-1);
}

void Ans_OUT(ll H, ll W, ll A, ll B, pair<ll,ll> notA_notB)
{
    if(notA_notB.first == -1)
    {
        OUT0("No");
    }
    else
    {
        vector<ll> tate(H,A);
        for(ll i=0;i<notA_notB.first;i++)
        {
            tate[i] = W-A;
        }
        vector<ll> yoko(W,B);
        for(ll i=0;i<notA_notB.second;i++)
        {
            yoko[i] = H-B;
        }
        vector<vector<ll>> graph(H,vector<ll>(W,0));
        for(ll i=0;i<H;i++)
        {
            for(ll j=0;j<W;j++)
            {
                if(tate[i]>0 && yoko[j]>0)
                {
                    graph[i][j] = 1;
                    tate[i]--;
                    yoko[j]--;
                }
            }
        }
        /*
        for(ll i=0;i<H;i++)
        {
            if(tate[i]!=0)
            {
                OUT0("-1");
                return;
            }
        }
        for(ll i=0;i<W;i++)
        {
            if(yoko[i]!=0)
            {
                OUT0("-1");
                return;
            }
        }*/
        ALLOUT2_WITHOUT_SPACE(graph);
    }
}

int main()
{
    ll H,W,A,B;
    cin >> H >> W >> A >> B;

    pair<ll,ll> notA_notB = Graph(H,W,A,B);

    Ans_OUT(H,W,A,B,notA_notB);
    
    return 0;
}