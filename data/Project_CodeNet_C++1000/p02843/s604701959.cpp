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
    int x;
    cin>>x;
    vi dp(x+1,0);
    dp[100] = dp[101] = dp[102] = dp[103] = dp[104] = dp[105] = 1;

    for(int i=200;i<=x;i++){
        if(dp[i-100]!=0 || dp[i-101]!=0 || dp[i-102]!=0 ||dp[i-103]!=0 || dp[i-104]!=0 ||dp[i-105]!=0)  dp[i] = 1;
    }
    cout<<dp[x]<<endl;
   /* 
    if(x>=2000){
        cout<<1<<endl;
        return 0;
    }
    int i=100,j=5;
    vi allowed;
    for(int k=i;k<=i+j;){
        allowed.pb(k);
        if(k==i+j){
            i += 100;
            j += 5;
            k = i;
        }
        else    k++;
        if(k==2000) break;
    }
    //for(int i=0;i<allowed.size();i++)
    //    cout<<allowed[i]<<" ";
    //cout<<endl;
    if(binary_search(all(allowed), x))  cout<<1<<endl;
    else                                cout<<0<<endl;
    */
    return 0;
}

