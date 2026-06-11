#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int main(){
   int n;
   cin>>n;

   set<int> st;
   for(int i=0; i<n; i++){
        int x;
        cin>>x;
        st.insert(x);
   }

   cout<<(n==st.size() ? "YES": "NO");


}


