#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
   string st;
   cin>>st;
   int l=st.size();
   //cout<<l;
   if(l<=t) cout<<st<<endl;
   else{

       cout<<st.substr(0,t)+"..."<<endl;
   }

}
