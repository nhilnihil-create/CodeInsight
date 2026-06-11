#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 1000000000
#define loop(i,a,b) for(int i=a;i<b;i++)
int main()
{
    //freopen("contest.txt","r",stdin);
    //freopen("contest.txt","w",stdout);
    IOS
    int n;
    cin>>n;
    map<string,string> m;
    string a,b;
    loop(i,0,n){
        cin>>a;
        m.insert(pair<string,string>(a,a));
    }
    cout<<m.size()<<endl;

}
