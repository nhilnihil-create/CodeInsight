#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;cin>>s;
    long long q;cin>>q;
    long long w=0;
    for(long long i=0;i<q;i++){
        int c;cin>>c;
        if(c==1){
            w++;
        }
        if(c==2){
            int d;cin>>d;
            string a;cin>>a;
            if(d==1){
                if(w%2==0)s.insert(0,a);
                else s.append(a);
            }
            else{
                if(w%2==0)s.append(a);
                else s.insert(0,a);
            }
        }
    }
    if(w%2==1)reverse(s.begin(),s.end());
    cout<<s<<endl;
}