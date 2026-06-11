#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LL long long
#define pii pair<int,int>
#define SZ(x)  (int)x.size()
#define all(x) x.begin(),x.end()

using namespace std;

LL gcd(LL a, LL b) {return b ? gcd(b, a % b) : a;}
LL lcm(LL a, LL b) {return a / gcd(a, b) * b;}
LL powmod(LL a, LL b, LL MOD) {LL ans = 1; while (b) {if (b % 2)ans = ans * a % MOD; a = a * a % MOD; b /= 2;} return ans;}
const int N = 5e5 + 3;
const LL mod = 1e9 + 7;
int n;
int a[(1<<18)+30];
int b[(1<<18)+30];
int cnt=0;
bool sta[(1<<18)+30];
int cmp1(int x,int y){
	return a[x]>a[y];
}
int main() {
	ios::sync_with_stdio(false);
    cin>>n;
    int turn=n;
    for(int i=1;i<=(1<<n);i++)cin>>a[i];
    n=(1<<n);
    sort(a+1,a+1+n,[](int x,int y){return x>y;});
    vector<int>res,tmp;
    res.pb(1);
    sta[1]=1;
    for(int i=1;i<=turn;i++){
        tmp=res;
        int l=1;
        int now=0;
        while(l<=n&&now<tmp.size()){
            if(sta[l])l++;
            else if(a[tmp[now]]>a[l]){
                now++;
                res.pb(l);
                sta[l]=1;
                l++;
            }else{
            	l++;
            }
        }
        sort(all(res),cmp1);
        if(now!=tmp.size())return cout<<"No\n",0;
    }
    cout<<"Yes\n";
    return 0;
}
//5 4 4 4 3 3 3 2
//5 4 4 3
//5 4 4  3 4 3 