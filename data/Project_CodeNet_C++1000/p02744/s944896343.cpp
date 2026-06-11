#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define INF 10000000000000000LL
#define ll  long long 
const long long  inf =1e18+44;
const int MAX=3e5+9;
const ll MOD=1e9+7;
const int TOT_PRIMES=1e6+9;
const int MAX_A=71;
const int LN=20;
const double eps=1e-1;
using namespace std;
int dp[2000][2000];
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n;
    cin>>n;
    queue<string>q;
    q.push("a");
    while(!q.empty()){
        string now = q.front();
        q.pop();
        if(now.size()==n){
            cout<<now<<endl;
            continue;
        }
        char mx = now[0];
        for (int i=0;i<now.size();i++)
            mx= max(mx, now[i]);
        for(char c= 'a';c<=mx+1;c++){
            now.push_back(c);
            q.push(now);
            now.pop_back();
        }
    }

}
