#include<bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
int main()
{
string s; cin>>s;
ll c=0,c1=0;
ll k=s.size();
for(ll i=0;i<k/2;i++)
{
    if(s[i]!=s[k-i-1])
    {
        c++;
    }
//    else
//    {
//        c1=1;
//    }
//}
//if(c1){
//ll n=k-c;
//if(k%2==1)
//cout<<n<<endl;
//else
//    cout<<n-1<<endl;
//}
//else
//{
//    cout<<0<<endl;
//}
}
cout<<c<<endl;
}