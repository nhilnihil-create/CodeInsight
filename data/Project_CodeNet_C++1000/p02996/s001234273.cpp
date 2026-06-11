/*
ID: learnin7
TASK: test
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<bits/stdc++.h>

/*  Macros from Endagorion */
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;


int main(){
        
    ios_base::sync_with_stdio(0);
    
    //ofstream fout ("test.out");
    //ifstream fin ("test.in");
    //fin >> a >> b;
    //fout << a+b << endl;
    int n;
    cin>>n;
    vpi x;
    forn(i,n){
        int a,b;
        cin>>a>>b;
        x.pb(mp(b,a));
    }
    //forn(i,n)   cout<<x[i].fi<<" "<<x[i].se<<endl;
    sort(all(x));
    //forn(i,n)   cout<<x[i].fi<<" "<<x[i].se<<endl;
    int sum = 0;
    forn(i,n)
    {
        int f = x[i].fi;
        int s = x[i].se;
        if((sum+s) <= f){
            sum += s;
     //       cout<<sum<<endl;
        }
        else{
            cout<<"No\n";
            return 0;
        }
    }
    cout<<"Yes\n";
    return 0;
}

