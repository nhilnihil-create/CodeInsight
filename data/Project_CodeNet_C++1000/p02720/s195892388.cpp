#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<memory>
#include<functional>
#include<set>
#include <cassert>
 
using namespace std;
 
#define ALL(g) (g).begin(),(g).end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define P(p) cout<<(p)<<endl;
#define PP(p) cout<<(p)<<" ";
#define INF 1e18

typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
//int dy[8]={1,1,1,0,-1,-1,-1,0};
//int dx[8]={-1,0,1,1,1,0,-1,-1};
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int pic(int n,int d){
    rep(i,d-1)n/=10;

    return n%10;
}
unsigned GetDigit(unsigned num){
    unsigned digit=0;
    while(num!=0){
        num /= 10;
        digit++;
    }
    return digit;
}/*
bool check(int n){
    int d =GetDigit(n);
    bool f = true;
    for(int i= 1;i<d;i++){
        if(abs(pic(n,i)-pic(n,i+1))>1){
            f = false;
        }
    }
    return f;
}
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    vi a;
    int k,cnt=0;
    cin>>k;
    for(int i = 1;;i++){
        if(check(i)){
            cnt++;
            if(cnt==k){
                cout << i << endl;
                return 0;
            }
        }
    }
    return 0;
}*/
signed main(){
    queue<int> q;
    int cnt = 0,k;
    cin>>k;
    for(int i = 1;i<10;i++)q.push(i);
    int t;
    while(true){
        t = q.front();
        q.pop();
        int t1 = t%10;
     //   int tm = pic(t,GetDigit(t));
        if(t1!=0){
            q.push(10*t+t1-1);
            if(cnt==k)break;
        }
        q.push(10*t+t1);
        cnt++;
        if(cnt==k)break;
        if(t1!=9){
            q.push(10*t+t1+1);
            if(cnt==k)break;
        }      
    }
    cout << t << endl;
}
