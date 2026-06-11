#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define forn(i,a,b) for(long long i=a;i<b;i++)
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

string s;cin>>s;
ll q;cin>>q;
deque<char> bc;
for(ll i=0;i<(ll)s.sz;i++){
    bc.push_back(s[i]);
}

int c=0;
bool flag=0;

while(q--){
    int opc;cin>>opc;
    if(opc==1){
        //reverse(all(bc));
       //c++;
       flag = !flag;
    }
    if(opc==2){
        int op;
        char a;
        cin>>op;
        cin>>a;
        if(flag){
            if(op==1){
                op++;
            }else{
                op--;
            }
        }
        if(op==1){
            //inicio
            bc.pf(a);
        }else{
            //final
            bc.pb(a);
        }
    }

}

/*for(auto &x:bc){
    cout<<x;
}*/
if(flag){
    for(int i=bc.sz-1;i>=0;i--){
        cout<<bc[i];
    }
    cout<<endl;
}else{
    for(auto &x:bc){
        cout<<x;
    }
    cout<<endl;
}
}

