#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define In_The_Name_Of_Allah_The_Merciful ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Alhamdulillah return 0;
#define all(v) v.begin(),v.end()
#define debug(n) cerr << "[" << #n << " = " << n << "]" << endl 

const int N = 1e5+5;
const ll mod = 1e9+7;
int n , m;
ll dp[N];
set <int> s;

ll calc (int idx){

    if (idx > n)
        return 0;

    if (idx == n)
        return 1;

    if (~dp[idx])
        return dp[idx];

    dp[idx] = 0;
    if (!s.count(idx+1))
        dp[idx] += calc(idx+1);
    dp[idx] %= mod;
    if (!s.count(idx+2))
        dp[idx] += calc(idx+2);
    dp[idx] %= mod;

    return dp[idx];
}

void Suhaib_Sawalha (){

    cin >> n >> m;
    for (int i = 0 , a ; i < m ; ++i){
        cin >> a;
        s.insert(a);
    }

    memset(dp,-1,sizeof dp);
    cout << calc(0);

}

int main(){
                                In_The_Name_Of_Allah_The_Merciful   /* بسم الله الرحمن الرحيم  */
#ifndef ONLINE_JUDGE
    freopen("SuhaibSawalha1.txt","r",stdin);
#endif
//int _;for(cin>>_;_;--_,cout<<'\n')
        Suhaib_Sawalha();
                                         Alhamdulillah                    /* الحمد لله */
}