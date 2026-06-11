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
int max_int = 1000000007;
void Debug(auto a);
int nibul(auto a,auto b);
int nibuu(auto a,auto b);
void input(vector<auto>& a,int n);
double PI = 3.14159265358979;
int n;

int ld_(string s1,string s2){
    if(s1.size() == 0) return s2.size();
    if(s2.size() == 0) return s1.size();
    if(s1[0] == s2[0]) return ld_(s1.substr(1),s2.substr(1));
    int l1 = ld_(s1,s2.substr(1));
    int l2 = ld_(s1.substr(1),s2);
    int l3 = ld_(s1.substr(1),s2.substr(1));
    return 1 + min({l1,l2,l3});
}

int ld(string s1,string s2){
    if(s1.size() == 0) return s2.size();
    if(s2.size() == 0) return s1.size();
    int n = s1.size()+1;
    int m = s2.size()+1;
    twovec(dp,n,m);
    REP(i,n){
        dp[i][0] = i;
    }
    REP(i,m){
        dp[0][i] = i;
    }
    FOR(i,1,n){
        FOR(j,1,m){
            int cost = 1;
            if(s1[i-1] == s2[j-1]) cost = 0;
            dp[i][j] = min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+cost});
        }
    }
    /*
    REP(i,n){
        Debug(dp[i]);
    }
    */
    return dp[n-1][m-1];

}



signed main(){
    string s1,s2;
    cin >> s1 >> s2;
    print(ld(s1,s2));

    return 0;
}

void Debug(auto a){
    cout << "{ ";
    for(auto b: a){
        cout << b << " ";
    }
    cout << "}" << endl;
}

//key以上の初めてのitr
int nibul(auto a,auto b){return lower_bound(All(a),b) - a.begin();}
//key以下の最後のitr
int nibuu(auto a,auto b){return upper_bound(All(a),b) - a.begin()-1;}

void input(vector<auto>& a,int n){
    REP(i,n){
        cin >> a[i];
    }
}

