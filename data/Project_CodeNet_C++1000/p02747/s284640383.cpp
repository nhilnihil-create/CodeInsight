#include<bits/stdc++.h>
#define inf 1000000000
#define eb emplace_back
#define pb push_back
#define fi first
#define se second
#define fastread ios::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef set<int> si;
typedef multiset<int> msi;
typedef map<int,int> mii;
int main()
{
    fastread;
    string str;
    cin>>str;
    for(int i=0;str[i];i+=2){
        if(str[i]!='h' || str[i+1]!='i'){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}
