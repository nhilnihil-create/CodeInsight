#include<bits/stdc++.h>
typedef long long ll;
#define  fi0(i,n)  for(int i=0;i<n;i++)
#define   pb()    push_back()
#define   mk()    make_pair()
#define   fst      first
#define   scnd    second
using namespace std;
int f[500], c;
void solve()
{
    string s[]={ "SUN","MON", "TUE", "WED", "THU", "FRI", "SAT","SUN"};
    int n;
    string ss;
    cin >> ss;

    for(int i=0;i<8;i++)
    if(ss==s[i]){
        n=i;
        break;
    }

    for(int j=n+1;j<8;j++){
        if(s[j]=="SUN")
        {
            cout<<j-n<<endl;
            return;
        }
    }
}
ll without()
{
}
void pairwise(ll n)
{

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ///int t;cin>>t;while(t--){ solve();}
    solve();
}
