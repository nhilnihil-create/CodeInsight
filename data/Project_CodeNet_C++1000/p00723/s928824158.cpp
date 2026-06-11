#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,j;
    cin>>n;
    while(n--){
        set<string> s;
        string st;
        cin>>st;
        s.insert(st);
        for(int i=1;i<st.size();i++){
            string q1,q2,q3,q4;
            q1=st.substr(0,i);
            q3=st.substr(i);
            q2=q1;
            q4=q3;
            reverse(q2.begin(),q2.end());
            reverse(q4.begin(),q4.end());
            s.insert(q1+q3);
            s.insert(q1+q4);
            s.insert(q2+q3);
            s.insert(q2+q4);
            s.insert(q3+q1);
            s.insert(q3+q2);
            s.insert(q4+q1);
            s.insert(q4+q2);
        }
        cout<<s.size()<<endl;
    }
    return 0;
}
 