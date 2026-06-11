#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
    cin>>n>>m;
    vector<int> p(m);
    vector<string> s(m);
    vector<int> t(n+1,0);
    int ans_wa=0;

    for(int i=0;i<m;++i){
        cin>>p.at(i)>>s.at(i);
    }
    for (int i=0;i<m;++i){
        if(s.at(i)=="AC"){
            if(t.at(p.at(i))==-1){
                continue;
            }
            ans_wa+=t.at(p.at(i));
            t.at(p.at(i))=-1;
        }
        else if(s.at(i)=="WA"){
            if(t.at(p.at(i))==-1){
                continue;
            }
            else{
                t.at(p.at(i))+=1;
            }
        }
    }
    int ans_ac=count(t.begin(),t.end(),-1);

    cout<<ans_ac<<" "<<ans_wa<<endl;
}