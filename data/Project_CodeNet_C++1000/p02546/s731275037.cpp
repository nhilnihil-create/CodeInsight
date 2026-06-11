#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	string st;
    cin>>st;
    
    if(st[st.size()-1]=='s'){
        st.push_back('e');
        st.push_back('s');
    }
    else st.push_back('s');
    
    cout<<st;
    
    return 0;
}