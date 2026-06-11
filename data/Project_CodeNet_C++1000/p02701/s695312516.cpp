#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    set <string> st;
    cin>>n;

    while(n--){
        string s;
        cin>>s;
        st.insert(s);
    }
    cout<<st.size()<<endl;


    return 0;
}
