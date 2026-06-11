#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int n,m;
    cin>>n>>m;
    int s,c;
    int ans;
    int ret=0;
    string k2;
    vector<int>vs(m);
    vector<int>vc(m);
    for(int i=0; i<m; i++){
        cin>>s>>c;
        s--;
        vs.at(i)=s;
        vc.at(i)=c;
    }
    for(int k=0; k<=999; k++){
        k2=to_string (k)  ;
        if(k2.size()!=n){
            continue;
        }
        ret=0;
        for(int j=0; j<m; j++){
            if(k2.at(vs.at(j))!=vc.at(j)+'0'){
                ret++;
            }
        }
        if(ret==0){
            cout<<k2<<endl;
            return 0;
        }
    }
    cout<<"-1"<<endl;
}
