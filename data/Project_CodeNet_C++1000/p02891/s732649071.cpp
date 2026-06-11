#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

char s[105];

int k;

int main(){
    cin>>s+1;
    cin>>k;

    int n=strlen(s+1);

    char ch=s[1];
    int cur=1;

    vector<pair<char,int>> v;
    for(int i=2;i<=n;++i){
        if(s[i]==ch){
            ++cur;
        }else{
            v.push_back(make_pair(ch,cur));
            ch=s[i];
            cur=1;
        }
    }

    if(cur){
        v.push_back(make_pair(ch,cur));
    }


    LL res;
    if((int)v.size()==1){
        cout<<1ll*n*k/2;
    }else{
        if(v[0].first!=v.back().first){
            int t=0;
            for(auto& it:v){
                t+=it.second/2;
            }
            res=1ll*t*k;
        }else{
            int x=(v[0].second+v.back().second)/2;
            int t=0;
            for(int i=1;i<(int)v.size()-1;++i){
                t+=v[i].second/2;
            }

            res=1ll*x*(k-1)+1ll*t*k;
            res+=v[0].second/2+v.back().second/2;
        }

        cout<<res;
    }

    return 0;
}
