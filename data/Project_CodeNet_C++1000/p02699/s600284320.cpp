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
    int w,s;
    cin>>s>>w;
    if(w>=s)
        cout<<"unsafe"<<endl;
    else
        cout<<"safe"<<endl;
    return 0;
}
