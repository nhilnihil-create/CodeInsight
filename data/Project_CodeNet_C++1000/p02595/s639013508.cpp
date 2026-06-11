#include <bits/stdc++.h>
using namespace std;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;
*/
typedef long long ll;
#define pb push_back 
#define mp make_pair
#define f first
#define s second
#define sz(x) ((int)x.size())
const ll maxint=2e18;
const ll minint =-2e18;

/*******\
(͡ ° ͜ʖ ͡ °) : Hello there, relax.
\*     */
double dist(double a,double b){
    // sqrt(p^2+q^2)
    return sqrt(a*a+b*b);
}
const int eps = -(1e9+7);
int main(){
    double n,d;
    cin>>n>>d;
    double a,b;
    int res = 0;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(d >= dist(a,b) )res++;
    }
    cout<<res<<'\n';
    return 0;
}