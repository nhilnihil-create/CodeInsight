/*
 AUTHOR : ANSHU BABU RAJPUT
 
    JAI MAA SARASWATI
    OM NAMAH SHIVAY
    JAI SHRI KRISHNA
    JAI SHRI RAM
    BHARAT MATA KI JAI

    #PKMKB	
    #CKMKB
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int  long long 
#define endl    ("\n")
#define ff       first
#define ss      second
#define pb   push_back
#define pf  push_front
#define ppb   pop_back
#define ppf  pop_front
#define mp   make_pair
#define mod 1000000007

#define L(x)    x.length()
#define B(x)     x.begin()
#define E(x)       x.end()
#define F(x)     x.front()
#define SZ(x)     x.size()
#define CLR(x)   x.clear()

#define all(x)                      x.begin(),x.end()
#define sortD(x) sort(x.begin(),x.end(),greater<int>)
#define rev(x)             reverse(x.begin(),x.end())

#define intV vector<int>

#define PI          (3.141592653589)
#define PMAX     priority_queue<int>
#define PMIN             priority_queue<int,vi,greater<int>>
#define setbits(x)                   __builtin_popcountll(x)
#define zrobits(x)                        __builtin_ctzll(x)

#define KING(i, n) for (int(i) = 0; (i) < n; (i)++)
#define MAHAKAL(i, n) for (int(i) = n-1; (i) >= 0; (i)--)

#define Anshu        int t; cin>>t; while(t--)
#define SITARAM(n,type) type* input=new type[n]

mt19937                          rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void ViLiFY_KiNG()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w",stderr);
#endif
}
 
int32_t main()
{
    ViLiFY_KiNG();
    int n,m;
    cin>>n>>m;

    int n_count = 0;
    int m_count = 0;

    if(n != 0 && n != 1) {
        n_count  = ((n-1)*n)/2;
    }

    if(m != 0 && m != 1) {
        m_count = ((m-1)*m)/2;
    }

    cout<<(m_count+n_count)<<endl;
    return 0;
}