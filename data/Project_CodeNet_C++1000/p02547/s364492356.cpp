#include <iostream>
#include <algorithm>
using namespace std;

#include <cmath>    //floor ceil
#include <cstdlib>  //abs
#include <cstdio>
#include <climits>  //INT_MAX
#include <cstring>
#define endl "\n"
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define lli long long int
#define lui long unsigned int
//#define int long long
#define MOD 1000000007
#define input(a,n) for (int i=0;i<n;i++) scanf("%d",&a[i]);
#define output(a,n) for (int i=0;i<n;i++) printf("%d ",a[i]);
#define rajnikant bool ios_base::sync_with_stdio(false); cin.tie(0);
#include <vector>
#define pb push_back
#define vi vector<int>
#include <map>
#define mp make_pair
#define mii map<int,int>
mii m,m1;
#include <set>
set<int>::iterator its;
#define f first
#define s second
#define all(v) v.begin(),v.end()
#include <stack>
/*---------------------------------------------------CODE STARTS FROM HERE---------------------------------------------------*/

int main () {
    int tt=1,t;
    //cin >> tt;
    while(tt--) {
        int n,c=0,b=0;
        cin >> n;
        int a[n][2];
        for (int i=0;i<n;i++) {
            cin >> a[i][0] >> a[i][1];
        }
        for (int i=0;i<n;i++) {
            if(a[i][0]==a[i][1]) c++;
            else c=0;
            if(c==3) {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
        cout<<"No"<<endl;
    }
    return 0;
}
