#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,m;
    cin>>n>>m;

    int clear=0, pena=0, p;
    string s;
    map<int, int> ac;
    map<int, int> wa;
    
    while(m--){
        cin>>p>>s;
        if(ac[p])   continue;
        if(s=="AC"){
            clear++;
            ac[p]=1;
            pena+=wa[p];
        }else if(s=="WA"){
            wa[p]++;
        }
    }
    
    cout<<clear<<" "<<pena<<endl;
    return 0;
}