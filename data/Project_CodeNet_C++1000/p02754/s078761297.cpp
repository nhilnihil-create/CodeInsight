#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
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

int main(){
fastIO;
#ifdef LOCAL
     freopen("in.txt", "r", stdin);
#endif

ll n,az,ro;
cin>>n>>az>>ro;
if(az==0){
    cout<<0<<endl;
}else if(az+ro==n){
    cout<<az<<endl;
}else{
    ll sobra = n%(az+ro);
    ll ocup = (n/(az+ro))*az;
    cout<<ocup + min(sobra,az)<<endl;
}
}

