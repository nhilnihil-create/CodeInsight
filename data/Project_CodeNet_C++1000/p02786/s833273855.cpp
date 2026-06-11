#include<iostream>
#include<vector>
#define lli long long int
#include<climits>
#include<unordered_map>
#include<algorithm>
#include<bitset>
#include<map>
#include<cmath>
#include<queue>
#define pb push_back
#define N (int)(1e5)
using namespace std;
using namespace std;
int main()
{
    lli h;
    cin>>h;
    lli ans = 0;
    lli val = 1;
    
    while(h!=0)
    {
        h = h/2;
        ans = ans + val;
        val = val*2;
    }
    
    cout<<ans<<endl;
    
    
    

}

