#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
int main(){
    string s;
    int q;
    cin>>s>>q;
    bool flag=0;
    rep(i,q){
        int a;
        cin>>a;
        if(a==1){
            flag=!flag;
        }
        else if(a==2){
            int f;
            char c;
            cin>>f>>c;
            f--;
            if(flag){
                f=!f;
            }
            if(f==0){
                s.insert(s.begin(),c);
            }
            else{
                s+=c;
            }
        }
    }
    if(flag) reverse(s.begin(),s.end());
    cout<<s<<endl;
}
