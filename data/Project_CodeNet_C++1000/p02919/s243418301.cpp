#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <bitset>     //UWAGA - w czasie kompilacji musi byc znany rozmiar wektora - nie mozna go zmienic
#include <cassert>
#include <iomanip>        //do setprecision
#include <ctime>
#include <complex>
using namespace std;

#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORQ(i,b,e) for(int i=(b);i<=(e);++i)
#define FORD(i,b,e) for(int i=(b)-1;i>=(e);--i)
#define REP(x, n) for(int x = 0; x < (n); ++x)

#define ST first
#define ND second
#define PB push_back
#define PF push_front
#define MP make_pair
#define LL long long
#define ULL unsigned LL
#define LD long double
#define pii pair<int,int>
#define pll pair<LL,LL>
#define vi vector<int>
#define vii vector<vi>

const double pi = 3.14159265358979323846264;
const int mod=1000000007;

int main(){
	int n;
    cin>>n;
    vi a(n);
    vi b(n);
    FOR(i,0,n){
        cin>>a[i];
        b[a[i]-1]=i;
    }
    set<int> st;
    LL ans=0;
    st.insert(-1);
    st.insert(-2);
    st.insert(n);
    st.insert(n+1);
    st.insert(b[n-1]);

    FORD(i,n-1,0){
        st.insert(b[i]);
        auto itr=st.lower_bound(b[i]);
        auto r1=next(itr);
        auto r2=next(r1);
        auto l1=--itr;
        auto l2=--itr;
        auto r1v=*r1;
        auto r2v=*r2;
        auto l1v=*l1;
        auto l2v=*l2;
        if(r2v==n+1)r2v=n;
        if(l2v==-2)l2v=-1;
        ans+=1LL*(r2v-r1v)*(b[i]-l1v)*(i+1)+1LL*(l1v-l2v)*(r1v-b[i])*(i+1);
        //cerr<<ans<<endl;
    }
    cout<<ans;

}
