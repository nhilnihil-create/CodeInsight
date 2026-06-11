#include<iostream>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin>>s;
    deque<char> dq(s.size());
    for(int i=0;i<s.size();++i) dq[i]=s[i];

    int q;
    cin>>q;
    bool is_reversed=false;
    for(int i=0;i<q;++i){
        int t;
        cin>>t;
        if(t==1) is_reversed=!is_reversed;
        else{
            int f;
            char c;
            cin>>f>>c;
            if(f==1){
                if(!is_reversed) dq.push_front(c);
                else dq.push_back(c);
            }
            else{
                if(!is_reversed) dq.push_back(c);
                else dq.push_front(c);
            }
        }
    }

    if(is_reversed) reverse(dq.begin(),dq.end());
    
    for(auto c:dq) cout<<c;
    cout<<endl;
}