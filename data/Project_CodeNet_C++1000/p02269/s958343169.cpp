#include<bits/stdc++.h>
#define loop(vals,times) for(vals=0;vals<times;vals++)
#define reg(time) for(int val=0;val<time;val++)
#define space <<" "<<
using namespace std;

int main()
{
    int n;
    set<string> dic;
    
    cin>>n;
    reg(n){
        string c,w;

        cin>>c>>w;
        if(c=="insert"){
        dic.insert(w);
        }
        if(c=="find"){
            
        if(dic.count(w)!=1)cout<<"no"<<endl;
         else cout<<"yes"<<endl;
        }
    }
}

