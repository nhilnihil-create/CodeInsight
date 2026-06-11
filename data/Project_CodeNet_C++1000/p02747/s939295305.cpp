#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(void){
    string s;
    cin>>s;
    if(s.size()%2!=0){
        cout<<"No"<<endl;
        return 0;
    }else{
        for(int i=0;i<s.size();i++){
            if(i%2==0){
                if(s[i]!='h'){
                    cout<<"No"<<endl;
                    return 0;
                }
            }else{
                if(s[i]!='i'){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"Yes"<<endl;
    
}
