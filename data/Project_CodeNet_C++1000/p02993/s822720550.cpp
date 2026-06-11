#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define forn(i,a,b) for(ll i=a;i<b;i++)
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
typedef pair<string,int> psi;
typedef pair<char,char> pcc;
typedef pair<double,double> pdd;
typedef pair<long long,long long> pll;
//cout << fixed << setprecision(12) <<x<<endl;

int main(){
fastIO;
#ifdef LOCAL
     freopen("in.txt", "r", stdin);
#endif

string s;
cin>>s;
bool flag =1;
forn(i,0,s.sz-1){
    if(s[i]==s[i+1]) flag=0;
}
if(flag){
    cout<<"Good"<<endl;
}else{
    cout<<"Bad"<<endl;
}
}

