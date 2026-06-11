#include<bits/stdc++.h>

using namespace std;

char s[500005];

int a[500005];

int main(){
    cin>>s+1;

    int n=strlen(s+1);

    long long res=0;

    vector<int>v;
    for(int i=1;i<=n;++i){
        if(s[i]=='<'&&s[i-1]!='<'){
            a[i]=0;
            v.push_back(i);
        }
    }
    for(auto x:v){
        for(int i=x;;++i){
            if(s[i]=='<'){
                a[i+1]=a[i]+1;
            }else{
                break;
            }
        }
    }

    v.clear();
    for(int i=n;i>=1;--i){
        if(s[i]=='>'&&s[i+1]!='>'){
            a[i+1]=0;
            v.push_back(i);
        }
    }
    for(auto& x:v){
        for(int i=x;;--i){
            if(s[i]=='>'){
                a[i]=max(a[i],a[i+1]+1);
            }else{
                break;
            }
        }
    }


    for(int i=1;i<=n+1;++i)res+=a[i];

    cout<<res;

    return 0;
}
