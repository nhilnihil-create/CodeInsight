#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n,ans;
    cin>>n;
    set<string>st;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        st.insert(s);
    }
    cout<<st.size()<<endl;
    }
