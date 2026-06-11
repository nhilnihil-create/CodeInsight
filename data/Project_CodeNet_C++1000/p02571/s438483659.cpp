//hail to jwalaji
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    lli mina=1e18;
    string s,t;
    cin>>s>>t;
    for(lli i=0;i<s.size()-t.size()+1;++i){
            //cout<<"i : "<<i<<endl;
            lli temp=0;
        for(lli j=0;j<t.size();++j){
            if(t[j]!=s[i+j]){
                temp++;
            }
        }
        mina=min(mina,temp);
    }
    cout<<mina<<endl;
return 0;
}
