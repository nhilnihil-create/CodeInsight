#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main() {
    string N;cin>>N;
    int d=N.size();
    int ans=0;
    int carry=false;
    int carryor=false;
    for (int i = d-1; i >= 0; i--){
        int tmp=(int)N[i]-(int)'0';
        if(carry)tmp++;
        if(carryor&&tmp>=5)tmp++;
        carry=false;carryor=false;
        if(tmp<=4)ans+=tmp;
        else if(tmp==5){
            ans+=5;
            carryor=true;
        }else{
            ans+=10-tmp;
            carry=true;
        }
    }
    if(carry)ans++;
    cout<<ans<<endl;
}