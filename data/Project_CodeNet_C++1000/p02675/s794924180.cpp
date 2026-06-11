#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
int main()
{
    IOS;
    //freopen("inputfile.txt","r",stdin);
    string s;cin>>s;
    if(s[s.size()-1]=='2' || s[s.size()-1]=='4'||s[s.size()-1]=='5'||s[s.size()-1]=='7'||s[s.size()-1]=='9')cout<<"hon"<<endl;
    else if(s[s.size()-1]=='3')cout<<"bon"<<endl;
    else cout<<"pon"<<endl;
    return 0;
}
//............ALHAMDULLILAH...........
