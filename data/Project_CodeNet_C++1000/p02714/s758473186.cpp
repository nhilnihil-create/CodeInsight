#include <bits/stdc++.h>


typedef long long ll;

using namespace std;



int main(){
    int N;
    string s;
    
    cin>>N;
    cin>>s;
    
    ll count=0;
/*
for(int i=0;i<4000;++i){
        int x=0+(int)(rand()*(2-0+1.0)/(1.0+RAND_MAX));
        if(x==0)s+='R';
        else if(x==1)s+='G';
        else if(x==2)s+='B';
    }
*/
    

    for(int i=0;i<N;++i){
        for(int j=i+1;2*j-i<N;++j){
            int k=j+j-i;
            if(s[i]==s[j])continue;
            if(s[j]==s[k])continue;
            if(s[k]==s[i])continue;
                ++count;
            
        }
    }
    vector<ll> vec(3,0);
    for(int i=0;i<N;++i){
        if(s[i]=='R'){
            ++vec[0];
        }else if(s[i]=='G'){
            ++vec[1];
        }else{
            ++vec[2];
        }
    }

   // cout<<count<<endl;

    if(N<=2){
        cout<<0<<endl;
    }else{
        cout<<vec[0]*vec[1]*vec[2]-count<<endl;
    }

    
}
