#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define F first
#define S second
#define ALL(a) a.begin(),a.end()
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORN(i,a,b) for(int i=a;i<=b;i++)
#define FORB(i,a,b) for(int i=a;i>=b;i--)
#define INT_MAXI 2147483647
#define INT_MINI -2147483648
#define REV(a) reverse(a.begin(),a.end())
#define NP(a) next_permutation(a.begin(),a.end())

typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //cout<<"input"<<endl;freopen("input.txt","r",stdin);
    //cout<<"output"<<endl;freopen("output.txt","w",stdout);
    
    int n;
    cin>>n;
    int sum = 0;
    for(int i=1;i<=n-1;i++){
        sum+=(n-1)/i;
    }
    cout<<sum<<endl;
    
    
    
    
    
    return 0;
}