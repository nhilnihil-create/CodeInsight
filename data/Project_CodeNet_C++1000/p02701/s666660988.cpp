#include<bits/stdc++.h>
using namespace std;


int main(void){
    int N;
    cin>>N;
    set<string> v;
    for(int i=0;i<N;i++){
      string s;
      cin>>s;
      v.insert(s);
    }
    cout<<v.size()<<endl;
    return 0;
}


