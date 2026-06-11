
///----> bismillahir rahmanir rahim <---- -- { ^ _ ^ }
///     { ^_^ }   { ^ _ ^ }



#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi; ///VECTOR<VECTOR<INT>NAME>NAME 2
typedef vector<vl> vvl;///LONG LONG
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;///VECTOR WITH PAIR
typedef vector<pll> vll;
typedef double dl;

#define endl "\n"
#define PB push_back
#define F first
#define S second
#define as(a) (a).begin(),(a).end()
#define ras(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007

#define over return 0;

#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))

#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu () {            cerr << endl;}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest) {cerr << arg << ' ';faltu(rest...);}

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }


///--------> YOUR JOURNEY STARTS HERE <-------



int main(){

string h;
cin>>h;
int j=h.length(); int hh=0;
    int ii=0;if(h[0]=='i' || h[j-1]=='h'){
        cout<<"No"<<endl;

return 0;
    }
for(int i=0;i<j;i++){
    if(h[i]!='h' && h[i]!='i'){
        cout<<"No"<<endl;
        return 0;
    }

    else{
        for(int i=0;i<j;i++){
            if(h[i]=='h'){
                hh++;
                ii=0;
            }
            else if(h[i]=='i'){
                ii++;
                hh=0;
            }
            if(hh>1 || ii>1){
                cout<<"No"<<endl;
                return 0;
            }


        }
    }

}
  cout<<"Yes"<<endl;

over
}
