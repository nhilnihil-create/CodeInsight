#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define endl '\n'
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
const ll mod=1e9+7;
bool sortbysec(const pair<int,int>&a,const pair<int,int>&b)
{
    return (a.second<b.second);
}
int main()
{
    string s;
    cin>>s;
    if(s[0]==s[1]||s[1]==s[2]||s[2]==s[3])
        cout<<"Bad"<<endl;
    else
        cout<<"Good"<<endl;







}

















































