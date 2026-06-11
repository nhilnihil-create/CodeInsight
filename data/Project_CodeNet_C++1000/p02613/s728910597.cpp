#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0; i<n; i++)
#define fof(i,s,e) for(int i=s; i<e; i++)
#define fob(i,e,s) for(int i=e; i>=s; i--)

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define all(v) (v).begin(),(v).end() 
#define arl(v) (v).rbegin(),(v).rend() // from right
#define vmn(a) (*min_element(a.begin(),a.end())) // vector min   
#define vmx(a) (*max_element(a.begin(),a.end())) // vector max
#define MOD 1000000007
typedef long long ll;
typedef map<int, int> mi;
typedef unordered_map<int, int> umi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
void inn(int &number);
//-----------------------------------------------------------------------------

void code(){
    int n;
    cin>>n;

    int a=0, r=0, t=0, w=0;
    while(n--) {
        string s;
        cin>>s;

        if(s=="AC") a++;
        else if(s=="RE") r++;
        else if(s=="TLE") t++;
        else w++;
    }

    cout<<"AC x "<<a<<endl;
    cout<<"WA x "<<w<<endl;
    cout<<"TLE x "<<t<<endl;
    cout<<"RE x "<<r<<endl;


}

// ------------------------------------------------------------------------------

int main(){
    IOS;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
        
    int t=1;
    // cin>>t;
    fo(i,t) {
        //cout<<"Case #"<<i+1<<" :";
        code();
    }

    return 0;
}