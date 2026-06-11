#include<bits/stdc++.h>
using namespace  std;

#define ll long long int
vector<int> ad[29];

int main()
{
    int  a,p,q,i,j,k,n,m,x,y;

    string str,test;
    cin>>str>>test;
    int len=str.length();
    int lent=test.length();

    for(int i=0;i<len;i++){
        ad[(str[i]-'a')].push_back(i);
    }

    ll ct=0;
    int last=-1;
    bool bl=true;
    for(i=0;i<lent;){
        int id=test[i]-'a';
        if(ad[id].size()==0){
            bl=false;
            break;
        }

        vector<int> :: iterator it=upper_bound(ad[id].begin(),ad[id].end(),last);
        if(it==ad[id].end()){
            last=-1;
            ++ct;
        }
        else{
            last=ad[id][it-ad[id].begin()];
            ++i;
        }
    }

    if(!bl) cout<<"-1\n";
    else{
        ll ans=ct*len;
        ans+=(last+1);
        cout<<ans<<'\n';
    }
}
