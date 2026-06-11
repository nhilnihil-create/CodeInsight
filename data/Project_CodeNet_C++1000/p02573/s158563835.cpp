#include <bits/stdc++.h>
#define ll long long
#define ALL(x) x.begin(),x.end()
#define MOD (1000000000+7)
using namespace std;
#define PI 3.14159265359
#define tMOD 998244353
#define mkpr(x,y) make_pair(x,y)
 int N,M;
   int v[200400];
   int vs[203000]={0};
   
int root(int i){
    if(v[i]==i){
        return i;
    }
    else{
        return root(v[i]);
    }
}

int margego(int tibi,int deka){
    int rtibi =root(tibi),rdeka = root(deka);
if(rtibi==rdeka){
return 0;
}
else
{   
    if(vs[rtibi]<vs[rdeka]) swap(rtibi,rdeka);
    vs[rtibi]=vs[rdeka]+vs[rtibi];
    v[rdeka]=rtibi;
}
return 0;
}




int main(){

    cin>>N>>M;
    for(int i=0;i<N;i++){
        v[i]=i;
        vs[i]=1;
    }

    for(int i=0;i<M;i++){
        int tmp,tmp1;
        cin>>tmp>>tmp1;
        margego(tmp-1,tmp1-1) ;
    }
    int ans=0;
    for(int i=0;i<N;i++){
        ans =max(ans,vs[i]);
    }

    cout<<ans<<endl;
   

    
}



