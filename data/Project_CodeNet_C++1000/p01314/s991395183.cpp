#include <bits/stdc++.h>
#include <numeric>
#define REP(i, s, n) for (int i = s; i < n; ++i)
#define rep(i, n) REP(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define SORT_INV(c) sort((c).begin(), (c).end(), greater<int>())
#define IINF INT_MAX
#define LLINF LLONG_MAX
#define DEBUG true
#define LL long long
#define Num 1000000007
// sort(a.begin(), a.end(), std::greater<int>());
using namespace std;

int main(){
    while(true){
        int num=0;
        int temp;
        cin>>temp;
        if(temp==0) break;
        int i=1;
        int j=1;
        int ans=0;
        while(i<=temp){
            //if(DEBUG) cout<<ans<<endl;
            if(ans==temp){
                num++;
            }
            if(ans<=temp){
                ans+=i++;
                continue;
            }
            else{
                ans-=j++;
                continue;
            }
        }
        cout<<num<<endl;
    }
    return 0;
}
