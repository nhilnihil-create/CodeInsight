#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define forn(i,a,b) for(int i=a;i<b;i++)
#define ft first
#define sd second
#define sz size()
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<char,char> pcc;
typedef pair<double,double> pdd;
typedef pair<long long,long long> pll;
//cout << fixed << setprecision(12) <<x<<endl;
const int MAX=30;
int a[MAX];
int b[MAX];
int c[MAX];
int main(){
fastIO;
#ifdef LOCAL
     freopen("int.txt", "r", stdin);
#endif

int n;
cin>>n;
forn(i,0,n) cin>>a[i];
int sum=0;
forn(i,0,n){
    cin>>b[i];
    sum+=b[i];
}
forn(i,0,n) cin>>c[i];
forn(i,0,n-1){
   // if(i==0) continue;
    if(a[i]+1==a[i+1]){
        sum+=c[a[i]-1];
    }
}
cout<<sum<<endl;
}

