#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define int long long
#define vec(a,n) vector<int> (a)((n));
#define Vec(a,n) vector<string> (a)((n));
#define twovec(a,n,m) vector<vector<int>> a(n,vector<int>(m,0));
#define Twovec(a,n,m) vector<vector<double>> a(n,vector<double>(m,0));
#define P pair<int,int>
#define All(a) (a).begin(),(a).end()
#define Sort(a) sort(All(a));
#define Reverse(a) reverse(All(a));
#define PQ(n) priority_queue<P,vector<P>,greater<P>> (n)
#define pq(n) priority_queue<int> (n)
#define print(a) cout << (a) << endl
#define printD(a) cout << setprecision(15) << (a) << endl;
using namespace std;
int max_int = 2147483647;
int prime = 998244353;
void Debug(auto a);
int nibul(auto a,auto b);
int nibuu(auto a,auto b);
void input(vector<auto>& a,int n);
double PI = 3.14159265358979;
int n;


signed main(){
    int a,b;
    cin >> n >> a >> b;
    if((b-a)%2==0){
        print((b-a)/2);
    }
    else{
        print(min(a,n-b+1)+((b-a)/2));
    }
    return 0;
}

void Debug(auto a){
    cout << "{ ";
    for(auto b: a){
        cout << b << " ";
    }
    cout << "}" << endl;
}
int nibul(auto a,auto b){
    int x = lower_bound(All(a),b) - a.begin();
    //key以上の初めてのitr
    return x;
}
int nibuu(auto a,auto b){
    int x = upper_bound(All(a),b) - a.begin();
    //key以下の最後のitr
    return x-1;
}

void input(vector<auto>& a,int n){
    REP(i,n){
        cin >> a[i];
    }
}
