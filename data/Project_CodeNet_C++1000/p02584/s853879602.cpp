#include<bits/stdc++.h>
#include<stdio.h>
    
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define _USE_MATH_DEFINES
#define f first
//#define s second
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define INF 1000000000000000000
#define MAXN (int)(1e7)+1
#define MOD 1000000007
    
using namespace std;
    
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pwi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector< vector<pair<ll,ll > > > wGraph;
typedef vector<vector<ll> > graph;
//typedef vector<vector<ll> > matrix;

    
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<std::fixed;
    cout<<std::setprecision(2);
    
    ll X, K ,D;
    cin>>X>>K>>D;

    X = abs(X);
    ll quantos_D_termina_X = X/D;
    ll quantos_X_sobra_de_D = X%D;

    ll residuo = K-quantos_D_termina_X;

    if(K < quantos_D_termina_X) cout<<abs(X-D*K)<<endl;
    else cout<<abs(quantos_X_sobra_de_D - D*(residuo % 2 == 1))<<endl;

    return 0;   
}