#include<bits/stdc++.h>
using namespace std;
#define pb          push_back
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define endl        "\n"
#define fast        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define int         long long int
#define mod         1000000007
#define test        int t;cin>>t;while(t--)
#define REP(i,a,b)  for(int i=a,i<=b;i++)
#define MAXN        200001

int32_t main()
{
    string str;
    cin>>str;

    bool ok=true;
    map<char,int>mp;
    for(int i=0;i<4;i++){
        mp[str[i]]++;
    }

    if(mp.size()==2){
        for(auto x:mp){
            if(x.S!=2){
                cout<<"No"<<endl;
                return 0;
            }
        }
        cout<<"Yes"<<endl;
    }

    else
        cout<<"No"<<endl;

    return 0;
}