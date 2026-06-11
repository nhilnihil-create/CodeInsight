/*BISMILLAH
THE WHITE WOLF
NO DREAM IS TOO BIG AND NO DREAMER IS TOO SMALL*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<long long> vll;
typedef vector<int> vi;

#define io ios_base::sync_with_stdio(false)
#define pb push_back
#define eb emplace_back
#define mod   1000000007
#define PI 2*acos(0.0)
#define all(r)(r).begin(),(r).end()
#define dbg(a) cout<<#a<<" ->->->-> "<<a<<"\n"
#define inf 1000000000000000000
#define N 110
int dirx[] = {1, -1,0, 0}, diry[] = {0, 0, 1, -1};


//=============================================ASIFAZAD==============================================

int32_t main()
{
    //io;
//    vector<double> exp(1005);
//    for(int i = 1; i<= 1000; i++)
//    {
//        double aex = 0;
//        for(double j = 1; j <= i; j++)
//            aex += j/i;
//        exp[i] = aex;
//    }
    int n, k;
    cin>>n>>k;
    vector<double> inp(n);
    for(auto& x: inp) cin>>x;

    double ans = 0, ac = 0;
    int i = 0, bk = 0;
    while(i < n)
    {
        ans += (inp[i] + 1)/2.0;
        i++;
//        dbg(i);
//        dbg(bk);
        while(i - bk > k)
        {
            ans-= (inp[bk] + 1)/2.0;
            bk++;
        }
//        dbg(ans);
        ac = max(ac, ans);
    }
    printf("%.8f", ac);
    return 0;
}