
#include<bits/stdc++.h>
using namespace  std ;
typedef long long  ll;
typedef pair<ll, ll> Pll;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define rad(X) cout << (X) << endl
#define ASH(X) cout << (X) << " "
#define debug(x) cout << #x << " " << x << endl;
#define debug2(x,y) cout << #x << " " << x << " " << #y << " " << y << endl;
#define FOR(I,A,B) for(ll I = (A); I <= (B); I++)
#define cir(I,B,A) for(ll I = (A); I >=(B); I--)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define SORT(c) (sort(c.begin(),c.end()))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASES int ___T; cin >> ___T; for(int cs=1;cs<=___T;cs++)
#define FAST()  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll fx[] = {1, 1, 0, -1, -1, -1, 0, 1};
ll fy[] = {0, 1, 1, 1, 0, -1, -1, -1};
vector<ll>a,b,c;
map<ll,ll>m1,m2,m3;

/************************************************/

void Execute()
{
      ll N,NB,VAL,A,B,C,G,INC,DEC,L,R,D;
      cin >> N >>G;

      //14 3
      //1 2 3 4 5 6 7 8 9 10 11 12 13 14
      //atcoder

      ll atcoder = 0;
      ll ans=2*G;
      while(1)
      {
        if(N<1) break;
        N-=ans;
        N-=1;
        atcoder++;


      }

      cout<<atcoder<<endl;





}

int32_t main()
{
    //freopen("atomm.txt", "r", stdin);
    FAST();
    //CASES

        Execute();

}
