#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define in insert
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Maxn 4000007
const int INF = 1e9 + 5;
const int  N = 2e5 + 314;
void foo(){
    string s;
    cin>>s;
    int sz = s.size();
    if(sz%2){
        cout<<"No\n";
        return;
    }
    for(int i = 0; i < sz; i++){
        if(s[i%2]!="hi"[i%2]){
            cout<<"No\n";
            return;
        }
    }
    cout<<"Yes\n";
}
int main(){
    speed;
    int t=1;
    //cin>>t;
    while(t--)foo();
}