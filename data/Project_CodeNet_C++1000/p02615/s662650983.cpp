#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define inf 100000000000000000
#define mod 1000000007
#define MAX 100005
#define pb push_back
#define vit vector<int>::iterator
typedef pair<int,int> pii;
map<string,int>M;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    lint n;
    cin>>n;
    vector<lint> V(n);
    for(lint i=0;i<n;i++) cin>>V[i];
    sort(V.begin(),V.end());
    reverse(V.begin(),V.end());
    lint sum=V[0];
    lint pos=2;
    for(lint i=1;i<n;i++){
        if(pos!=n){
            sum+=V[i];
            pos++;
        }
        if(pos!=n){
            sum+=V[i];
            pos++;
        }
    }
    cout<<sum;
    return 0;
}
